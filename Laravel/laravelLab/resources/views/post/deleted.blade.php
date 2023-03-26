@extends('layouts.app')

@section('title') Deleted posts @endsection

@section('content')
    @if(count($posts)>0)
    <div class="d-flex justify-content-between mt-5">
        <x-button type="success" :href="route('posts.restoreAll')" label="Restore All" />
        <x-button type="danger" :href="route('posts.destroyAll')" label="Delete All permanantly" />
    </div>

    <table class="table my-4">
        <thead>
        <tr>
            <th scope="col">#</th>
            <th scope="col">Title</th>
            <th scope="col">Slug</th>
            <th scope="col">Posted By</th>
            <th scope="col">Created At</th>
            <th scope="col">Image</th>
            <th scope="col">Actions</th>
        </tr>
        </thead>
        <tbody>
        @foreach($posts as $post)
            <tr>
                <td class="align-middle">{{$post->id}}</td>
                <td class="align-middle">{{$post->title}}</td>
                <td class="align-middle">{{$post->slug}}</td>
                <td class="align-middle">{{$post->user->name}}</td>
                <td class="align-middle">{{$post['created_at']->format('Y-m-d')}}</td>
                @if($post->image == null)
                <td class="align-middle text-muted" style="font-size: 13px;">No Image</td>
                @else
                <td class="align-middle" style="max-width: 200px;">{{$post->image}}</td>
                @endif
                <td class="align-middle">
                    <x-button type="success" :href="route('posts.restore',$post->id)" label="Restore" />
                    <button type="button" class="btn btn-danger" data-bs-toggle="modal" data-bs-target="#exampleModal-{{$post->id}}">DELETE </button>
                    <form method="GET" action="{{route('posts.destroyPermanantly',$post->id)}}">
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
    @else
    <div class="card my-5 text-center">
        <div class="card-body">
            No deleted posts
        </div>
    </div>
    @endif
    <div class="d-flex justify-content-center mt-5">
        {{ $posts->links('pagination::bootstrap-4') }}
    </div>

@endsection
