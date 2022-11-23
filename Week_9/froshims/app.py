from flask import Flask, render_template, request 

app = Flask(__name__)

# Creating a global variable with sports - better design than listing each in index and in request.form
SPORTS = [
    "Basketball",
    "Football",
    "Soccer",
    "Frisbee",
]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def register():

    #Validate submission
    if not request.form.get("name") or request.form.get("sport") not in SPORTS: # Use global variable instead of listing each out
        return render_template("failure.html")
    
    #Confirm registratoin
    return render_template("success.html")
