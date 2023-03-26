<?php

namespace App\Http\Controllers;

use App\Models\User;
use Laravel\Socialite\Facades\Socialite;
use Illuminate\Support\Facades\Auth;

class OAuthController extends Controller
{
    public function redirect($provider)
    {
        return Socialite::driver($provider)->redirect();
    }

    public function callback($provider)
    {
        $providerUser = Socialite::driver($provider)->stateless()->user();
        $user = User::where('email', $providerUser->email)->first();
        if ($user) {
            $user->update([
                'provider_id' => $providerUser->provider_id,
                'provider_token' => $providerUser->token,
                'provider_refresh_token' => $providerUser->refreshToken,
            ]);
        } else {
            $user = User::create([
                'name' => $providerUser->name,
                'email' => $providerUser->email,
                'password' => $providerUser->token,
                'provider_id' => $providerUser->id,
                'provider_token' => $providerUser->token,
                'provider_refresh_token' => $providerUser->refreshToken,
            ]);
        }

        Auth::login($user);

        return redirect('/posts')->with('message', 'logged in successfully');
    }
}
