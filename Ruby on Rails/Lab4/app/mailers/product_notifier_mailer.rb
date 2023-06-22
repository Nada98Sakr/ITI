class ProductNotifierMailer < ApplicationMailer


  def new_product_mail
    mail(to: "nada@test.com", subject: "New product created")
  end

end
