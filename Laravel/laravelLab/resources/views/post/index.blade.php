@extends('layouts.app')

@section('title') Index @endsection

@section('content')
    <div class="text-center mt-5">
        <x-button type="success" :href="route('posts.create')" label="Create Post" />
    </div>
    <table class="table mt-4">
        <thead>
        <tr>
            <th scope="col">#</th>
            <th scope="col">Title</th>
            <th scope="col">Posted By</th>
            <th scope="col">Created At</th>
            <th scope="col">Actions</th>
        </tr>
        </thead>
        <tbody>

        @foreach($posts as $post)
            <tr>
                <td>{{$post->id}}</td>
                <td>{{$post->title}}</td>
                <td>{{$post->user->name}}</td>
                <td>{{$post['created_at']->format('Y-m-d')}}</td>
                <td>
                    <x-button type="info" :href="route('posts.show',$post->id)" label="View" />
                    <x-button type="primary" :href="route('posts.edit',$post->id)" label="Edit" />
                    @if($post->trashed())
                        <x-button type="danger" :href="route('posts.restore',$post->id)" label="Restore" />
                    @else
                        <button type="button" class="btn btn-danger" data-bs-toggle="modal" data-bs-target="#exampleModal-{{$post->id}}">DELETE </button>
                    @endif

                    <form method="POST" action="{{route('posts.destroy',$post->id)}}">
                        @method('DELETE')
                        @csrf
                        <div class="modal fade" id="exampleModal-{{$post->id}}" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
                            <div class="modal-dialog modal-dialog-centered">
                                <div class="modal-content">
                                    <div class="modal-header">
                                        <h5 class="modal-title">Are you sure you want to Delete this</h5>
                                        <button type="button" class="btn-close" data-bs-dismiss="modal" aria-label="Close"></button>
                                    </div>
                                    <div class="modal-footer">
                                        <button type="button" class="btn btn-primary" data-bs-dismiss="modal">NO</button>
                                        <button type="submit" class="btn btn-danger">YES</button>
                                    </div>
                                </div>
                            </div>
                        </div>
                </form>
                </td>
            </tr>
        @endforeach

        </tbody>
    </table>
    <div class="d-flex justify-content-center mt-5">
        {{ $posts->links() }}
    </div>

@endsection
