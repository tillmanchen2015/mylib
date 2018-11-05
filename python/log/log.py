import logging

logger.setLevel(level=logging.DEBUG)
#dateTag = datetime.datetime.now().strftime("%y%m%d_%H%M%S")
#handler = RotatingFileHandler(filename="server_%s.log" % dateTag, maxBytes=10 * 1024 * 1024, backupCount=5)
needRoll = os.path.isfile('server.log')
handler = RotatingFileHandler(filename="server.log", maxBytes=10 * 1024 * 1024, backupCount=5)
handler.setLevel(logging.DEBUG)
formatter = logging.Formatter('%(asctime)s %(levelname)s %(message)s')
handler.setFormatter(formatter)
if(needRoll):
	handler.doRollover()

console = logging.StreamHandler()
console.setLevel(logging.DEBUG)
logger.addHandler(handler)
logger.addHandler(console)
logger.info("log is initialized")
