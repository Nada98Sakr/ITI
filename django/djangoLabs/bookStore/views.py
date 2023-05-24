from django.shortcuts import render, redirect
from .models import Book
from .forms import BookForm

# Create your views here.
book_list = Book.objects.all()

def index(request):
    my_context = {'book_list': Book.objects.all()}
    return render(request, 'index.html', context=my_context)

def add_book(request):
    form = BookForm()
    if request.method == "POST":
        form = BookForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect('bookStore:index')
    return render(request, 'create-book.html', context={'form': form})

def show_details(request, *args, **kwrgs):
    book_id = kwrgs.get('book_id')
    book = Book.objects.get(id=book_id)
    my_context = {'book': book}
    return render(request, "book-details.html",context=my_context)

def edit_book(request, id):
    book = Book.objects.get(id=id)
    form = BookForm(instance=book)
    if request.method == "POST":
        form = BookForm(data=request.POST, instance=book)
        if form.is_valid():
            form.save()
            return redirect("bookStore:index")  # Redirect to the appropriate page after saving
        
    return render(request, 'edit-book.html', context={
        'form': form, 
        'book': book
    })

def delete_book(request, id):
    Book.objects.get(id=id).delete()
    return redirect('bookStore:index')  
