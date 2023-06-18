class CreateBooks < ActiveRecord::Migration[7.0]
  def change
    create_table :books do |t|
      t.string :name
      t.decimal :price
      t.string :image
      t.text :description
      t.references :user, null: false, foreign_key: true

      t.timestamps
    end
  end
end
