<?php

namespace App\Http\Controllers\Api;

use App\Http\Controllers\Controller;
use App\Http\Resources\PostResource;
use App\Models\Post;
use App\Http\Requests\StorePostRequest;

class PostController extends Controller
{
    function index(){
        $posts = Post::all();
        return PostResource::collection($posts);
    }

    function show($id){
        $post = Post::find($id);
        return new PostResource($post);
    }

    function store(StorePostRequest  $request){
        $data = request()->all();
        $post = Post::create([
            'title' => $data['title'],
            'description' => $data['description'],
            'user_id' => $data['user_id'],
        ]);
        return new PostResource($post);
    }
}
