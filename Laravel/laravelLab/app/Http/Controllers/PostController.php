<?php

namespace App\Http\Controllers;


use App\Models\Post;
use App\Models\User;
use App\Models\Comment;
use Illuminate\Support\Facades\Storage;
use App\Http\Requests\StorePostRequest;

class PostController extends Controller
{
    public function index(){
        $posts = Post::paginate(5);
        return view("post.index",["posts" => $posts]);
    }

    public function DeletedPosts(){
        $posts = Post::onlyTrashed()->paginate(5);
        return view("post.deleted",["posts" => $posts]);
    }

    public function show($id){
        $post = Post::find($id);
        $comments = Comment::where('post_id', $id)->get();
        return view("post.show",["post" => $post,"comments" => $comments]);
    }

    public function edit($id){
        $post = Post::find($id);
        return view("post.edit",["post" => $post]);
    }

    public function destroy($id){
        $post = Post::find($id);
        Storage::delete(str_replace('storage', 'public', $post->image));
        $post->comments()->delete();
        $post->delete();
        return back();
    }

    public function restore($id){
        $post = Post::withTrashed()->find($id);
        $post->restore();
        return back();
    }

    public function create(){
        $users = User::all();
        return view("post.create",["users" => $users]);
    }

    public function store(StorePostRequest $request){
        if ($request->file('image')) {
            $image = $request->file('image');
            $imageName = $image->getClientOriginalName();
            $image = $request->file('image');
            $imageName = explode('.',$image->getClientOriginalName());
            $imageName = $imageName[0].$request->id.'.'.$imageName[1];
            $imagePath = $image->storeAs('public/images', $imageName);
            $imagePath = $image->storeAs('public/images', $imageName);

            Post::create([
                'title' =>  $request['title'],
                'description' =>  $request['description'],
                'user_id' => $request['creator'],
                'image' => str_replace('public', 'storage', $imagePath)
            ]);
        } else {
            Post::create([
                'title' =>  $request['title'],
                'description' =>  $request['description'],
                'user_id' => $request['creator']
            ]);
        }

        return redirect()->route('posts.index');
    }

    public function update(StorePostRequest $request, $id){
        $post = Post::find($id);
        if ($request->file('image')) {
            Storage::delete(str_replace('storage', 'public', $post->image));
            $image = $request->file('image');
            $imageName = explode('.',$image->getClientOriginalName());
            $imageName = $imageName[0].$id.'.'.$imageName[1];
            $imagePath = $image->storeAs('public/images', $imageName);
        } else {
            $imagePath = $post->image;
        }
        $post->update([
            'title' => $request['title'],
            'description' => $request['description'],
            'image' => str_replace('public', 'storage', $imagePath),
        ]);
        return redirect()->route('posts.index');
    }
}
