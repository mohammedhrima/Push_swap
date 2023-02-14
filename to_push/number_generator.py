import os
import random
num = int(input("Enter you range : "))
# numbers = random.sample(range(-10*num, 10 * num), num)
numbers = [3716, 2855, 1873, 3020, 2624, 3552, 453, 683, 4812, 316, 4439, 1783, 4588, 436, 2141, 2914, 1501, 2500, 4922, 4128, 2168, 738, 1358, 2722, 1854, 3105, 3089, 2570, 4515, 3444, 222, 3283, 1495, 3860, 1019, 1673, 1839, 535, 4229, 2870, 3180, 207, 2078, 795, 4791, 1519, 3773, 1996, 2005, 4746, 1964, 1751, 1578, 1391, 2099, 4191, 3841, 3620, 4288, 4593, 487, 1461, 4385, 4033, 1214, 2801, 2028, 4655, 4224, 655, 826, 4427, 3901, 3268, 2961, 4759, 583, 2183, 1582, 868, 2053, 902, 2671, 4682, 1232, 4284, 831, 4637, 18, 552, 4086, 4533, 2237, 700, 470, 888, 1162, 1163, 1307, 3355, 4946, 1695, 1480, 2504, 1087, 4778, 2013, 2979, 657, 4048, 4613, 4645, 3832, 1626, 2792, 3913, 4591, 3155, 1302, 2439, 554, 1790, 4105, 4030, 4411, 3975, 3631, 4493, 1700, 476, 3291, 467, 4277, 629, 985, 654, 633, 997, 2514, 2450, 804, 4614, 1716, 4762, 4919, 1838, 3724, 214, 3473, 3198, 1196, 92, 1444, 3001, 3333, 1374, 4155, 2045, 1264, 2812, 33, 4142, 4000, 2499, 221, 2326, 948, 2611, 519, 2299, 4258, 1792, 2820, 2242, 3602, 4462, 309, 4576, 596, 3847, 2077, 3292, 679, 477, 1345, 3543, 1108, 3316, 4285, 4764, 4161, 1885, 4260, 372, 3516, 2920, 2575, 4377, 1558, 4218, 3613, 349, 4131, 5, 2693, 4219, 4304, 947, 67, 4460, 1308, 3727, 4861, 1894, 2562, 1080, 3655, 2913, 1010, 3190, 3651, 498, 1680, 4114, 4818, 2592, 2284, 1707, 2357, 1761, 2994, 3664, 707, 1206, 49, 4840, 905, 1930, 3374, 385, 4524, 2868, 3381, 2853, 3960, 2755, 1243, 286, 2206, 1740, 2239, 4702, 4808, 225, 4931, 149, 2365, 4471, 4276, 199, 1014, 208, 2363, 3214, 3605, 1177, 3167, 4571, 3878, 354, 4319, 3050, 1960, 1824, 966, 1994, 4787, 4983, 1105, 4157, 4306, 708, 2258, 1644, 2244, 3090, 3041, 3205, 2184, 2103, 4352, 4085, 2465, 4853, 480, 2984, 3979, 2109, 2434, 1357, 706, 1572, 70, 3454, 3056, 1713, 3129, 822, 558, 3487, 2380, 2238, 4013, 3642, 1355, 4844, 2749, 194, 1844, 4384, 3662, 4113, 2272, 3396, 725, 1517, 1533, 897, 2902, 1068, 4268, 1633, 3532, 1478, 3606, 59, 4421, 1640, 2534, 3544, 3118, 1709, 1842, 276, 2871, 1342, 1317, 2088, 1919, 4971, 274, 2698, 849, 973, 108, 614, 1165, 2997, 856, 2787, 1530, 1344, 2080, 572, 4043, 32, 2481, 2331, 3537, 3600, 1763, 1328, 2298, 158, 1893, 3738, 295, 2176, 20, 3426, 2297, 4708, 4156, 3455, 3163, 2003, 234, 2436, 3110, 3207, 2906, 1113, 2716, 343, 2050, 3211, 4918, 2253, 1450, 1318, 1392, 1368, 3710, 375, 378, 4024, 4226, 2492, 2526, 601, 1414, 4132, 1880, 4928, 974, 4080, 4438, 2143, 3922, 1179, 30, 4106, 715, 2441, 3689, 1827, 515, 1562, 1806, 1419, 1338, 4620, 4488, 4536, 995, 783, 3705, 750, 2180, 3476, 317, 1624, 483, 1509, 516, 747, 3994, 1496, 2897, 1646, 172, 4175, 4976, 2207, 4584, 4060, 2539, 2169, 3560, 579, 541, 3309, 2085, 2859, 1987, 3404, 3128, 3902, 2017, 3257, 1988, 1285, 2110, 2231, 739, 4943, 213, 1874, 643, 2406, 727, 4302, 1347, 3308, 2259, 4848, 4436, 744, 3149, 2432, 3762, 19, 681, 1587, 4314, 3141, 4649, 4451, 3709, 4023] 
# print(' '.join(str(x) for x in numbers))
print(numbers, "\n")
os.system("make fclean && make && ./push_swap " + ' '.join(str(x)
          for x in numbers) + " | wc -l")
