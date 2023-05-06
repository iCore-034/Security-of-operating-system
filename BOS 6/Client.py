import socket
import pickle

import random
from Cryptodome.Util.number import *


class One_Pass_Authentication:
    def __init__(self):
        self.socket = socket.socket()
        self.socket.connect(('localhost', 9090))
        self.n = 0
        self.s = 0
        self.v = 0

    def input(self):
        self.message = str(input("please input message: "))
        self.send((str(bytes_to_long(self.message.encode("utf-8"))).encode("utf-8")))
        publick_key = self.recv_pickle()
        self.transform_data(publick_key)
        self.check_data()
        # self.n = int(self.recv())

        # self.confirm_data_to_decimal_form()
        #
        # self.v = pow(self.s, 2, self.n)
        # print(f"N : {self.n}\n"
        #       f"S : {self.s}\n"
        #       f"V : {self.v}\n")
        #
        # self.send(str(self.v).encode("utf-8"))
        # self.check_data()
    def transform_data(self,dict):
        self.n = dict['N']
        self.e = dict['E']
        self.y = dict['Y']
        self.x = dict['X']
        print(f"N = {self.n}\n"
              f"E = {self.e}\n"
              f"X = {self.x}\n"
              f"Y = {self.y}\n")
        
    def check_data(self):
        no_of_iterations = 40
        for i in range(no_of_iterations):
            r = random.randint(1, self.n - 1)
            a = pow(r, self.e, self.n)

            self.send(str(a).encode("utf-8"))

            c = int(self.recv())

            z = (r*(self.x**c)) % self.n
            self.send(str(z).encode("utf-8"))

    def send(self, data):
        self.socket.send(data)

    def confirm_data_to_decimal_form(self):
        self.s = bytes_to_long(self.message.encode("utf-8"))

    def recv(self):
        tmp = self.socket.recv(1024)
        tmp = tmp.decode("utf8")
        return tmp
    def recv_pickle(self):
        tmp = self.socket.recv(1024)
        try:
            tmp = pickle.loads(tmp)
            return tmp
        except:
            print("error")
if __name__ == '__main__':
    One_Pass_Authentication = One_Pass_Authentication()
    One_Pass_Authentication.input()