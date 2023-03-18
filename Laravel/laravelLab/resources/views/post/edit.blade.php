@extends('layouts.app')


@section('title') Index @endsection

@section('content')
<form method="POST" action="{{route('posts.store')}}" class="mt-5">
    @csrf
    <div class="mb-3">
        <label for="exampleFormControlInput1" class="form-label">Title</label>
        <input type="text" name="title" class="form-control" id="exampleFormControlInput1" placeholder="" value="{{$post['title']}}">
    </div>
    <div class="mb-3">
        <label for="exampleFormControlTextarea1" class="form-label">Description</label>
        <textarea class="form-control" name="description" id="exampleFormControlTextarea1" rows="3">{{$post['description']}}</textarea>
    </div>

    <div class="mb-3">
        <label for="exampleFormControlTextarea1" class="form-label">Post Creator</label>
        <select name="creator" class="form-control">
            <option value="Ahmed">Ahmed</option>
            <option value="Mohamed">Mohamed</option>
            <option value="Mahmoud">Mahmoud</option>
        </select>
    </div>
    <button type="submit" class="btn btn-success">EDIT</button>
</form>
@endsection
