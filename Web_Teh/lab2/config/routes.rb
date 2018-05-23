Rails.application.routes.draw do

   root to: "pages#landing"
   get "features" => "pages#features"
   get "landing" => "pages#landing"
end
