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
                <td>{{$post['id']}}</td>
                <td>{{$post['title']}}</td>
                <td>{{$post['post_creator']}}</td>
                <td>{{$post['created_at']}}</td>
                <td>
                    <x-button type="info" :href="route('posts.show',$post['id'])" label="View" />
                    <x-button type="primary" :href="route('posts.edit',$post['id'])" label="Edit" />
                    <x-button type="danger" :href="route('posts.delete',$post['id'])" label="DELETE" />
                </td>
            </tr>
        @endforeach



        </tbody>
    </table>

@endsection
