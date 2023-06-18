class BooksController < ApplicationController
  http_basic_authenticate_with name: "nada", password: "123456", except: [:index, :show]
  def index
    @books=Book.all
  end

  def show
    @book= Book.find(params[:id])
  end

  def new
    @book = Book.new
  end

  def create 
    @book=Book.new(book_params)
    @book.user_id = User.find_by(name: authenticated_username).id
    @book.image = save_image(params[:book][:image])
    p @book
    if @book.save
      redirect_to book_path(@book)
    else 
      render :new, status: :unprocessable_entity 
    end
  end

  def edit 
    @book= Book.find(params[:id])
  end

  def update
    @book= Book.find(params[:id])
    if @book.update(book_params)
      redirect_to @book
    else 
      render :edit,status: :unprocessable_entity
    end 
  end

  def destroy
    @book= Book.find(params[:id])
    @book.destroy
    redirect_to root_path ,status: :see_other
  end

  private
  def save_image(image)
    timestamp = Time.now.strftime("%Y%m%d%H%M%S")
    extension = File.extname(image.original_filename).downcase
    filename = "#{timestamp}_#{SecureRandom.hex(8)}#{extension}"
    filepath = Rails.root.join('public', 'images', filename)

    File.open(filepath, 'wb') do |file|
      file.write(image.read)
    end

    filename
  end

  private
  def authenticated_username
    username, _password = ActionController::HttpAuthentication::Basic::user_name_and_password(request)
    username
  end

  private
  def book_params
    params.require(:book).permit(:name, :image ,:price, :description )
  end
end
