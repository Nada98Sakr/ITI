from django.shortcuts import render, redirect

# Create your views here.
book_list = [
    {
        'id': 1,
        'name': 'book1',
        'price': 200,
        'description': 'lorem ipsum book description'
    },
    {
        'id': 2,
        'name': 'book2',
        'price': 200,
        'description': 'lorem ipsum book description'
    },
    {
        'id': 3,
        'name': 'book3',
        'price': 200,
        'description': 'lorem ipsum book description'
    },
    {
        'id': 4,
        'name': 'book4',
        'price': 200,
        'description': 'lorem ipsum book description'
    }
]

def index(request):
    my_context = {'book_list': book_list}
    return render(request, 'index.html', context=my_context)

def add_book(request):
    id = len(book_list) + 1
    new_book = {
        'id': id,
        'name': 'book'+ str(id),
        'price': 200,
        'description': 'lorem ipsum book description'
    }
    book_list.append(new_book)
    return redirect('bookStore:index') 

def show_details(request, *args, **kwrgs):
    book_id = kwrgs.get('book_id')
    book = _get_book(book_id)
    my_context = {'book': book}
    return render(request, "book-details.html",context=my_context)

def edit_book(request, *args, **kwrgs):
    book_id = kwrgs.get('book_id')
    book = _get_book(book_id)
    for task in book_list:
        if task == book:
            task['name'] = f"Update {book['name']}"
            
    return redirect('bookStore:index') 

    return render(request, "book-edit.html")

def delete_book(request, *args, **kwrgs):
    book_id = kwrgs.get('book_id')
    book = _get_book(book_id)
    if book:
        book_list.remove(book)
    return redirect('bookStore:index') 

def _get_book(book_id):
    for book in book_list:
        if 'id' in book and book['id'] == book_id:
            return book
    return None

