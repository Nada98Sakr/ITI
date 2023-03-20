<?php

namespace App\Http\Controllers;


use App\Models\Post;
use App\Models\User;
use App\Models\Comment;
use App\Http\Requests\StorePostRequest;
use Illuminate\Http\Request;
use Illuminate\Support\Facades\Date;

class PostController extends Controller
{
    public function index(){
        $posts = Post::withTrashed()->paginate(5);
        return view("post.index",["posts" => $posts]);
    }

    public function show($id){
        $post = Post::find($id);
        $comments = Comment::where('post_id', $id)->get();;
        return view("post.show",["post" => $post,"comments" => $comments]);
    }

    public function edit($id){
        $post = Post::find($id);
        return view("post.edit",["post" => $post]);
    }

    public function destroy($id){
        $post = Post::find($id);
        $post->delete();
        return redirect()->route('posts.index');
    }

    public function restore($id){
        $post = Post::withTrashed()->find($id);
        $post->restore();
        return redirect()->route('posts.index');
    }

    public function create(){
        $users = User::all();
        return view("post.create",["users" => $users]);
    }

    public function store(StorePostRequest $request){
        Post::create([
            'title' => $request->title,
            'description' => $request->description,
            'user_id' => $request->creator
        ]);
        return redirect()->route('posts.index');
    }

    public function update(StorePostRequest $request, $id){
        $post = Post::find($id);
        $post->update([
            'title' => $request->title,
            'description' => $request->description
        ]);
        return redirect()->route('posts.index');
    }
}
