@extends('layouts.app')

@section('title') Show @endsection

@section('content')
    <div class="card mt-5">
        <div class="card-header">
            Post Info
        </div>
        <div class="card-body">
            <h5 class="card-title">Title: {{$post['title']}}</h5>
            <p class="card-text">Description: {{$post['description']}}</p>
        </div>
    </div>

    <div class="card mt-5">
        <div class="card-header">
            Post Creator Info
        </div>
        <div class="card-body">
            <h5 class="card-title">created by: {{$post['post_creator']}}</h5>
            <p class="card-text">created at: {{$post['created_at']}}</p>
        </div>
    </div>

@endsection
