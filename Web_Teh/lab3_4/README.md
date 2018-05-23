# Laboratory work nr.3-4 by Sclifos Corina

## User Autentification 
User authentication is a generic problem - many applications handle it. Therefore, it is safe to assume that there are standard practices or even readily available solutions for it. In Ruby, such a set of solutions is called a gem. You can think of a Ruby Gem as a library or plug-in.

The problems we need to address are generic and common across multiple Rails applications:
* Manage a database of users
* Allow your users to post content on your app
The gem we're using to solve these problems is Devise.

## Database
I using a database called SQLite. It is simple database, that can be used without additional configuration.
Now that I have Devise fully installed and configured, let's use it to generate a User table.
Use Devise to generate a model called User.
It also created a special file, called a migration.

## User
* Associating users and content
* Associating posts to users
* Letting the users delete cases
* Adding User page

## Restricting access
* Adding controller filters
* Restrict delete action to owners
* 
