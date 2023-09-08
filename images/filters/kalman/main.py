#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
# FileName:     main
# Author:       8ucchiman
# CreatedDate:  2023-06-01 19:03:12
# LastModified: 2023-02-18 14:28:37 +0900
# Reference:    8ucchiman.jp
# Description:  ---
#


import os
import sys
# import utils
# from utils import get_ml_args, get_dl_args, get_logger
# import numpy as np
# import pandas as pd

INTERVAL_SEC = 0.01
TIME_LIMIT_SEC = 10.0
INPUT_vELOCITY_MS = 10.0
INPUT_NOISE_VARIANCE = 10.0
OBSERVATION_NOISE_VARIANCE = 5.0


class LinearKalmanFilter3D:
    """
        Class to estimate 1 dimensional position by Linear Kalman Filter.
    """

    def __init__(self, interval_sec, input_velocity_ms, input_noise_variance, observation_noise_variance):
        """
            interval_sec: interval times to update this simulation
            input_velocity_ms: input velocity[m/s] into state equation
            input_noise_variance: variance of noise included in input velocity
            observation_noise_variance: variance of noise inculded in observation
        """
        self.DT = interval_sec
        self.V = input_velocity_ms
        self.Q = input_noise_variance
        self.R = observation_noise_variance

        # define parameters for state equation
        self.F = 1.0
        self.G = self.DT

        # define parameter for observation equation
        self.H = 1.0


def main():
    # args = utils.get_args()
    # method = getattr(utils, args.method)
    
    pass


if __name__ == "__main__":
    main()

