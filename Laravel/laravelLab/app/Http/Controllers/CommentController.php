<?php

namespace App\Http\Controllers;

use App\Models\Comment;
use Illuminate\Http\Request;

class CommentController extends Controller
{
    public function store(Request $request)
    {
        Comment::create([
            'user_id' => $request->user_id,
            'post_id' => $request->post_id,
            'comment' => $request->comment,
        ]);
        return back();
    }

    public function update($id){
        
    }
}
