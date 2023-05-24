from django.forms import TextInput, NumberInput
from django import forms
from .models import Book


class BookForm(forms.ModelForm):
    class Meta:
        model = Book
        fields = ['name', 'description', 'author_name', 'pages', 'price']
        widgets = {
            'name': TextInput(attrs={
                'class': "form-control w-100",
                'placeholder': 'Name'
                }),
            'description': TextInput(attrs={
                'class': "form-control w-100", 
                'placeholder': 'Description'
                }),
            'author_name': TextInput(attrs={
                'class': "form-control w-100", 
                'placeholder': 'Author Name'
                }), 
            'pages': NumberInput(attrs={
                'class': "form-control w-100",
                'placeholder': 'Pages'
                }),   
            'price': NumberInput(attrs={
                'class': "form-control w-100", 
                'placeholder': 'Price'
                }),    
        }