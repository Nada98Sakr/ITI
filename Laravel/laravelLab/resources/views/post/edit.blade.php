@extends('layouts.app')


@section('title') Index @endsection

@section('content')
<form method="POST" action="{{route('posts.update',$post['id'])}}" class="mt-5">
    @csrf
    @method('PUT')
    <div class="mb-3">
        <label for="exampleFormControlInput1" class="form-label">Title</label>
        <input type="text" name="title" class="form-control" id="exampleFormControlInput1" placeholder="" value="{{$post->title}}">
    </div>
    <div class="mb-3">
        <label for="exampleFormControlTextarea1" class="form-label">Description</label>
        <textarea class="form-control" name="description" id="exampleFormControlTextarea1" rows="3">{{$post->description}}</textarea>
    </div>

    <div class="mb-3">
        <label for="exampleFormControlTextarea1" class="form-label">Post Creator</label>
        <select name="creator" class="form-control">
            <option value="{{$post->user_id}}">{{$post->user->name}}</option>
        </select>
    </div>
    <button type="submit" class="btn btn-success">EDIT</button>
</form>
@endsection
