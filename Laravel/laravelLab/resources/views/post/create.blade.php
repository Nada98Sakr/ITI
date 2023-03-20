@extends('layouts.app')

@section('title') create @endsection

@section('content')

<form method="POST" action="{{route('posts.store')}}" class="mt-5">
    @csrf
    <div class="mb-3">
        <label for="title" class="form-label">Title</label>
        <input type="text" name="title" class="form-control @error('title') is-invalid @enderror" id="title" >
        @error('title')
            <div class="alert alert-danger mt-1">{{ $message }}</div>
        @enderror
    </div>
    <div class="mb-3">
        <label for="description" class="form-label">Description</label>
        <textarea class="form-control @error('description') is-invalid @enderror" name="description" id="description" rows="3"></textarea>
        @error('description')
            <div class="alert alert-danger mt-1">{{ $message }}</div>
        @enderror
    </div>

    <div class="mb-3">
        <label for="exampleFormControlTextarea1" class="form-label" required>Post Creator</label>
        <select name="creator" class="form-control">
            @foreach($users as $user)
                <option value="{{$user->id}}">{{$user->name}}</option>
            @endforeach
        </select>
    </div>
    <button type="submit" class="btn btn-success">Create</button>
</form>
@endsection
