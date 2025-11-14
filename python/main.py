from flask import Flask, request, render_template

app = Flask(__name__)

photo_val = 0

@app.route('/', methods=['GET', 'POST'])
def main():
    global photo_val

    if request.method == "POST":
        photo_val = request.get_data().decode("utf-8")

    return render_template("main.html", photo_val=photo_val)

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)
