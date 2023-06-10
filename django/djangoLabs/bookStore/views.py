from django.shortcuts import render, redirect
from .models import Book
from .forms import BookForm
from django.contrib.auth.decorators import login_required

book_list = Book.objects.all()

@login_required(login_url='/user/login')
def index(request):
    my_context = {'book_list': Book.objects.all()}
    return render(request, 'index.html', context=my_context)

@login_required(login_url='/user/login')
def add_book(request):
    form = BookForm()
    if request.method == "POST":
        form = BookForm(request.POST)
        if form.is_valid():
            form.save()
            return redirect('bookStore:index')
    return render(request, 'create-book.html', context={'form': form})

@login_required(login_url='/user/login')
def show_details(request, *args, **kwrgs):
    book_id = kwrgs.get('book_id')
    book = Book.objects.get(id=book_id)
    my_context = {'book': book}
    return render(request, "book-details.html",context=my_context)

@login_required(login_url='/user/login')
def edit_book(request, id):
    book = Book.objects.get(id=id)
    form = BookForm(instance=book)
    if request.method == "POST":
        form = BookForm(data=request.POST, instance=book)
        if form.is_valid():
            form.save()
            return redirect("bookStore:index") 
        
    return render(request, 'edit-book.html', context={
        'form': form, 
        'book': book
    })

@login_required(login_url='/user/login')
def delete_book(request, id):
    Book.objects.get(id=id).delete()
    return redirect('bookStore:index')  
