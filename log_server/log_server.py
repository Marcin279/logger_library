from http.server import BaseHTTPRequestHandler, HTTPServer
import threading

class LogRequestHandler(BaseHTTPRequestHandler):
    log_file_lock = threading.Lock()
    def do_POST(self):
        content_length = int(self.headers['Content-Length'])
        post_data = self.rfile.read(content_length)
        log_message = post_data.decode('utf-8')

        print("Received log: {}".format(log_message))

        self.save_log_to_file(log_message)

        self.send_response(200)
        self.end_headers()

    def save_log_to_file(self, log_message):
        with self.log_file_lock:
            with open("logs.txt", "a") as log_file:
                log_file.write(log_message + "\n")

def run(server_class=HTTPServer, handler_class=LogRequestHandler, port=8090):
    server_address = ('', port)
    httpd = server_class(server_address, handler_class)
    print(f'Starting server on port {port}...')
    httpd.serve_forever()

if __name__ == "__main__":
    run()
