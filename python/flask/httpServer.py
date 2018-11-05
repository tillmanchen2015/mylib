from flask import Flask
from flask import request
from flask import render_template
from flask import send_file
from flask import send_from_directory
import json
import common
from common import logger

app = Flask(__name__)

@app.route('/hello')
@app.route('/hello/<name>')
def hello(name=None):
    logger.info("request /hello")
    return render_template('hello.html', name=name)

@app.route('/course/videos')
def videos():
    logger.info('/course/videos')
    mark = request.args.get('mark', '')
    logger.info('mark: '+mark)
    if(mark == 0):
        logger.info("0: TODO...")
        pass
    elif(mark == 1):
        logger.info("1: TODO...")
        pass
    return "mark="+mark;

@app.route('/download/<filename>')
def download_file(filename):
    directory = r"C:\Users\007\PycharmProjects\test\static"
    return send_from_directory(directory, filename, as_attachment=True)

if __name__ == '__main__':
    common.init_log()
    app.run(debug=False)