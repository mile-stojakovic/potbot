from flask import Flask, request, render_template

app = Flask(__name__)

photo_val = 0
moisture_val = 0

@app.route('/', methods=['GET', 'POST'])
def main():
    global photo_val, moisture_val

    if request.method == "POST":
        raw_data = request.get_data().decode("utf-8")
        photo_val, moisture_val = raw_data.split(",")

    return render_template("main.html", photo_val=photo_val, moisture_val=moisture_val)

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)
