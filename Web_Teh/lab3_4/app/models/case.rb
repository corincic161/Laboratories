class Case < ActiveRecord::Base  
	belongs_to :user
	has_many :cases
end