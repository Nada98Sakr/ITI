<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;

class PostController extends Controller
{
    public function index(){
        $posts = [
            [
                'id' => 0,
                'title' => 'Laravel',
                'description' => "Laravel description",
                'post_creator' => 'Ahmed',
                'created_at' => '2023-04-16 10:37:00'
            ],
            [
                'id' => 1,
                'title' => 'PHP',
                'description' => "PHP description",
                'post_creator' => 'Mohamed',
                'created_at' => '2023-04-16 10:37:00'
            ],
            [
                'id' => 2,
                'title' => 'Javascript',
                'description' => "JS description",
                'post_creator' => 'Ali',
                'created_at' => '2023-04-16 10:37:00'
            ],
        ];
        return view("post.index",["posts" => $posts]);
    }

    public function show($id){
        $post = [
            'id' => 1,
            'title' => 'PHP',
            'description' => "PHP description",
            'post_creator' => 'Mohamed',
            'created_at' => '2023-04-16 10:37:00'
        ];
        return view("post.show",["post" => $post]);

    }

    public function edit($id){
        $post = [
            'id' => 1,
            'title' => 'PHP',
            'description' => "PHP description",
            'post_creator' => 'Mohamed',
            'created_at' => '2023-04-16 10:37:00'
        ];
        return view("post.edit",["post" => $post]);
    }

    public function delete($id){
        return "in delete";
    }

    public function create(){
        return view("post.create");
    }

    public function store(){
        return redirect()->route('posts.index');
    }
}
