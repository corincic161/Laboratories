Rails.application.routes.draw do
  devise_for :users
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
  resources :cases

  root to: "pages#landing"
  root to: "cases#index"
  get "features" => "pages#features"
  get "landing" => "pages#landing"
end
