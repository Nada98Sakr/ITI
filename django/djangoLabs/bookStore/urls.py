"""
URL configuration for djangoLabs project.

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/4.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""

from django.urls import path
from .views import *

app_name = 'bookStore'

urlpatterns = [
    path('', index, name="index"),
    path('details/<int:book_id>', show_details, name="show_details"),
    path('edit/<int:id>', edit_book, name="edit"),
    path('delete/<int:id>', delete_book , name="delete"),
    path('add/', add_book , name="add"),
]
