<?php

use Illuminate\Support\Facades\Route;
use Illuminate\Support\Facades\Auth;
use App\Http\Controllers\PostController;
use App\Http\Controllers\CommentController;
use App\Http\Controllers\OAuthController;
use PSpell\Config;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider and all of them will
| be assigned to the "web" middleware group. Make something great!
|
*/

Route::get('/', function () {
    return view('welcome');
});

Route::get("/posts/removeOld",[PostController::class,"removeOldPosts"]);

Route::group(['middleware' => 'auth'], function (){
    Route::get('/posts/deleted', [PostController::class,"DeletedPosts"])->name("posts.DeletedPosts");
    Route::get('/posts/destroyAll', [PostController::class,"destroyAllPermanently"])->name("posts.destroyAll");
    Route::get('/posts/restoreAll', [PostController::class,"restoreAll"])->name("posts.restoreAll");
    Route::resource('posts', PostController::class);
    Route::get('/posts/restore/{id}', [PostController::class,"restore"])->name("posts.restore");
    Route::get('/posts/destroyPermanantly/{id}', [PostController::class,"destroyPermanantly"])->name("posts.destroyPermanantly");
    Route::post('/comments', [CommentController::class, 'store'])->name('comments.store');
});

Auth::routes();

Route::get('/home', [App\Http\Controllers\HomeController::class, 'index'])->name('home');

Route::get('/auth/{provider}/redirect', [OAuthController::class, 'redirect'])->name('oauth.redirect');
Route::get('/auth/{provider}/callback', [OAuthController::class, 'callback'])->name('oauth.callback');
