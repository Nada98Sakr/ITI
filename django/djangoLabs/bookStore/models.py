from django.db import models

class Book(models.Model):
    name = models.CharField(max_length=50)
    price = models.DecimalField(max_digits=7, decimal_places= 3)
    description = models.TextField()
    author_name = models.CharField(max_length=20)
    pages = models.IntegerField(max_length=50)

    def __str__(self):
        return self.name
