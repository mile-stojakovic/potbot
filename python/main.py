from flask import Flask, request, render_template

app = Flask(__name__)

sensor_data = {
    "light": [],
    "moisture": []
}

@app.route('/', methods=['GET', 'POST'])
def main():
    global sensor_data

    if request.method == "POST":
        raw_data = request.get_data().decode("utf-8")
        data_pair = [int(x) for x in raw_data.split(",")]

        sensor_data["light"].append(data_pair[0])
        sensor_data["moisture"].append(data_pair[1])

    return render_template("main.html", sensor_data=sensor_data)

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5000)
