# Laravel Labs

Laravel Labs is a project that demonstrates how to build a simple blog application using Laravel, a popular PHP web framework. It consists of several features that allow users to create, edit, and delete blog posts, add comments, and login with GitHub and Google. Additionally, the project includes a queue job and task scheduling to automatically delete old posts.

## Routes

The following image displays the routes handled by the resource controller:

![Actions_Handled_By_Resource_Controller](https://user-images.githubusercontent.com/77510429/227795249-e6f22758-4fd1-4748-8438-095c9d0e7235.PNG)

## Deployment

To deploy the Laravel Labs project, you need to follow these steps:

1. Run `composer install` to install the required dependencies.
2. Run `php artisan key` to generate an application key.
3. Run `php artisan serve` to start the development server.

## Tables

The Laravel Labs project includes four tables:

* `users`: stores information about each user of the application, including their name, email address, password, slug, and image.
* `posts`: stores information about each post, including its id, title, description, author, slug, and image.
* `comments`: stores information about each comment on a post, including the comment body, author, and the ID of the post it belongs to.
* `tags`: stores information about tags associated with each post.

## Features

Laravel Labs includes the following features:

* Create new posts: users can create new posts and publish them to the site.
* Edit posts: users can edit and update existing blog posts.
* Delete posts: users can delete blog posts. The deleted posts are soft-deleted, which means they can be restored, permanently deleted, or restored all at once.
* Deleted posts: users can view a list of all deleted posts.
* Add comments: users can add comments to posts.
* Login with GitHub and Google.
* Queue job: deletes posts that were created two years ago.
* Task scheduling: runs the job daily at midnight.
* Pagination: The application uses pagination to display posts and comments in smaller, more manageable chunks. This makes it easier for users to navigate large amounts of content.

## Future work

There are several features that could be added to the Laravel Labs project in the future, such as:

* User profiles: each user could have their own profile where they can edit their information.
* Search for posts: users could search for specific posts based on keywords or tags.
* Edit and delete comments: users could edit or delete their comments on posts.
* Connect social accounts: users could have a button on their profile to connect their GitHub or Google accounts.

## Demo

A demo of the Laravel Labs project is available at [].



