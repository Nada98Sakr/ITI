@extends('layouts.app')

@section('title') Deleted posts @endsection

@section('content')
    <!-- <div class="text-center mt-5">
        <x-button type="success" :href="route('posts.create')" label="Restore All" />
        <x-button type="danger" :href="route('posts.create')" label="Delete All permanantly" />
    </div> -->

    <table class="table mt-4">
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
                <td class="align-middle" style="max-width: 150px;">{{$post->image}}</td>
                @endif
                <td class="align-middle">
                    <x-button type="danger" :href="route('posts.restore',$post->id)" label="Restore" />
                </td>
            </tr>
        @endforeach

        </tbody>
    </table>
    <div class="d-flex justify-content-center mt-5">
        {{ $posts->links('pagination::bootstrap-4') }}
    </div>

@endsection
