from http.client import REQUESTED_RANGE_NOT_SATISFIABLE
from flask import Flask, render_template, request 

# Need to run python -m flask run to create link!

app = Flask(__name__) # __name__ means the name of the file



# have to tell when to call index function, defining a route for slash. known as a DECORATOR, modifies another function
# @app.route("/") 
# def index():
#     name = request.args.get("name") #get the name from the URL .../?name=Aman
#     return render_template("index.html", name_of_person=name) # render this file aka print to user screen

@app.route("/")
def index():
    return render_template("index.html") # render this file aka print to user screen

@app.route("/greet", methods = ["POST"]) # Bc I created a new page, I need to route that url too. Enable POST here as well to hide name in URL 
def greet():
    name = request.form.get("name", "world") # world is a default value, but not robust, see required in index.html 
    return render_template("greet.html", name_of_person=name)


# request.args is for GET 
# request.form is for POST
