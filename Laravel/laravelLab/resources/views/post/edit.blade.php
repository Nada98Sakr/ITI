@extends('layouts.app')


@section('title') Index @endsection

@section('content')
<form method="POST" action="{{route('posts.update',$post['id'])}}" enctype="multipart/form-data" class="mt-5">
    @csrf
    @method('PUT')
    <div class="mb-3">
        <label for="title" class="form-label">Title</label>
        <input type="text" name="title" class="form-control @error('title') is-invalid @enderror" id="title" value="{{$post->title}}">
        @error('title')
            <div class="alert alert-danger mt-1">{{ $message }}</div>
        @enderror
    </div>
    <div class="mb-3">
        <label for="description" class="form-label">Description</label>
        <textarea class="form-control @error('description') is-invalid @enderror" name="description" id="description" rows="3">{{$post->description}}</textarea>
        @error('description')
            <div class="alert alert-danger mt-1">{{ $message }}</div>
        @enderror
    </div>

    <div class="mb-3">
        <label for="exampleFormControlTextarea1" class="form-label" >Post Creator</label>
        <select name="creator" class="form-control">
            <option value="{{$post->user_id}}">{{$post->user->name}}</option>
        </select>
    </div>

    <div class="mb-3">
        <label for="image" class="form-label">Add image</label>
        <!-- Add value to input -->
        <!-- {{str_replace('storage', 'public', $post->image)}} -->
        <input type="file" name="image" class="form-control" id="image" >
    </div>
    <button type="submit" class="btn btn-success">EDIT</button>
</form>
@endsection
