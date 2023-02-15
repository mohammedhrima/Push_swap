#include "../Libft/libft.h"
int moves = 0;
void swap_array(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

void sort_array(int *array_of_numbers, int *array_of_indexes, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < len)
	{
		i = len - 1;
		while (i > j)
		{
			if (array_of_numbers[j] < array_of_numbers[i])
			{
				swap_array(array_of_numbers + j, array_of_numbers + i);
				swap_array(array_of_indexes + j, array_of_indexes + i);
			}
			i--;
		}
		j++;
	}
}

// struct
typedef struct number
{
	int value;
	int index; // where it should go
} num;

typedef struct stack
{
	num *array_of_nums;
	int lenght;
} stack;

// rotate (up)
void rotate(stack *list)
{
	num tmp = list->array_of_nums[0];
	ft_memmove(list->array_of_nums, list->array_of_nums + 1, (list->lenght - 1) * sizeof(num));
	list->array_of_nums[list->lenght - 1] = tmp;
}

// reverse rotate (down)
void reverse_rotate(stack *list)
{
	num tmp = list->array_of_nums[list->lenght - 1];
	ft_memmove(list->array_of_nums + 1, list->array_of_nums, (list->lenght - 1) * sizeof(num));
	list->array_of_nums[0] = tmp;
}

// push
void push(stack *src, stack *dest)
{
	if (src->lenght)
	{
		num tmp = src->array_of_nums[0];
		rotate(src); // up
		src->lenght--;
		dest->lenght++;
		reverse_rotate(dest); // down
		dest->array_of_nums[0] = tmp;
		moves++;
	}
	else
	{
		printf("\n\"verify src len in push\"\n");
	}
}

// swap
void swap(stack *list)
{

	num tmp = list->array_of_nums[0];
	list->array_of_nums[0] = list->array_of_nums[1];
	list->array_of_nums[1] = tmp;
}

void cut_from_stack(stack *A, stack *B, int middle_index)
{
	int i = 0;
	int j = 0;
	int sa = 0;
	int sb = 0;
	printf("\nmiddle index : %d \nA lenght: %d\n", middle_index, A->lenght);
	while (i < middle_index)
	{
		if (A->array_of_nums[0].index >= middle_index)
		{
			printf("push(%d) ", A->array_of_nums[0].value);
			push(A, B);
			moves++;
			i++;
		}
		j = 0;
		while (j < A->lenght && A->array_of_nums[0].index <= middle_index)
		{
			if (A->array_of_nums[j].index >= middle_index)
			{
				printf("r ");
				rotate(A); // up
				moves++;
				break;
			}
			if (A->array_of_nums[A->lenght - j - 1].index >= middle_index)
			{
				printf("rr ");
				reverse_rotate(A); // down
				moves++;
				break;
			}
			j++;
		}
	}
}

int main(void)
{
	int i;
	// int middle;

	int const_array[] = {762, 424, 1920, 1669, 706, 1620, 1915, 328, 342, 910, 1358, 854, 1652, 1975, 1751, 1631, 1664, 408, 329, 584, 1759, 1984, 640, 1978, 950, 738, 928, 1227, 1806, 1329, 54, 1854, 623, 51, 832, 855, 1261, 1370, 814, 345, 1089, 1262, 1773, 1715, 938, 1678, 879, 682, 1987, 1476, 1725, 929, 204, 689, 753, 1189, 958, 296, 985, 693, 716, 1702, 681, 1583, 488, 183, 1032, 187, 1489, 75, 552, 1625, 178, 1601, 433, 892, 727, 778, 1011, 804, 1926, 812, 1506, 1194, 1344, 1039, 1074, 139, 22, 1159, 1524, 251, 585, 792, 1933, 1870, 156, 760, 1591, 603, 1797, 1172, 155, 109, 413, 1457, 233, 46, 1036, 1204, 1959, 875, 1642, 1618, 830, 1144, 915, 601, 1021, 1044, 1662, 1885, 1517, 5, 1716, 1084, 1549, 756, 452, 1342, 1387, 1431, 189, 1916, 993, 36, 1848, 1184, 1609, 282, 1337, 1108, 148, 754, 1833, 130, 690, 1430, 438, 648, 1299, 1058, 646, 1850, 1722, 1462, 952, 1671, 1241, 1985, 752, 1901, 357, 1948, 932, 726, 1029, 1012, 963, 1834, 834, 1170, 1165, 1658, 1830, 1566, 1018, 668, 625, 369, 1731, 1486, 253, 1447, 388, 1102, 538, 786, 829, 1180, 1289, 622, 1708, 1550, 1230, 1867, 137, 1925, 1640, 1743, 1163, 372, 78, 719, 1176, 1766, 528, 303, 159, 50, 31, 163, 1352, 658, 837, 1957, 6, 1200, 1463, 1557, 1452, 1758, 287, 655, 1469, 1995, 742, 783, 1310, 219, 872, 960, 1908, 1643, 39, 218, 415, 1215, 1287, 1801, 630, 4, 333, 143, 200, 1828, 691, 901, 1570, 1845, 1851, 1374, 520, 1953, 1280, 237, 1187, 1360, 609, 1783, 624, 1999, 1386, 95, 659, 524, 1466, 614, 362, 98, 1161, 1373, 451, 122, 1656, 532, 297, 1401, 300, 1810, 1760, 1498, 1866, 1569, 35, 907, 1090, 1054, 816, 893, 118, 864, 749, 1560, 407, 1048, 294, 1771, 647, 1520, 1746, 152, 404, 18, 818, 79, 1504, 858, 28, 1186, 336, 898, 1634, 1951, 120, 442, 74, 444, 14, 460, 1956, 1811, 1389, 72, 1714, 1808, 1929, 502, 888, 839, 782, 364, 491, 515, 1017, 1319, 1909, 660, 1145, 1216, 1355, 82, 1884, 269, 983, 405, 1981, 1841, 1628, 977, 76, 1391, 270, 642, 1441, 1065, 1635, 558, 770, 578, 549, 1028, 1362, 1063, 1033, 1300, 1894, 1060, 1077, 1990, 785, 1817, 1578, 1254, 1531, 522, 1449, 1081, 423, 1424, 275, 851, 815, 720, 284, 1917, 394, 264, 530, 274, 1712, 1734, 217, 1365, 1534, 1076, 1133, 1555, 176, 410, 1927, 15, 1675, 1267, 381, 1979, 1278, 1572, 1139, 384, 853, 583, 598, 1146, 523, 1616, 1556, 1644, 147, 1095, 1728, 1415, 546, 664, 283, 1599, 1091, 196, 1676, 581, 412, 1976, 1087, 618, 113, 1961, 1406, 1440, 577, 1655, 1997, 850, 41, 396, 831, 1932, 1846, 172, 468, 441, 1162, 1203, 1603, 479, 1328, 1382, 265, 58, 808, 1312, 539, 1053, 602, 1757, 1941, 1784, 1988, 1385, 1117, 1325, 699, 1519, 1351, 280, 326, 1307, 1461, 833, 1151, 1460, 1648, 916, 1795, 574, 1496, 1938, 48, 723, 1281, 1777, 1167, 1040, 661, 781, 1923, 9, 1607, 1467, 802, 116, 650, 1863, 238, 1143, 462, 1445, 431, 1354, 591, 1761, 1493, 500, 712, 1693, 1336, 936, 514, 1294, 777, 1427, 375, 1528, 774, 1136, 136, 965, 428, 881, 564, 86, 1944, 1295, 1745, 1922, 325, 1889, 1363, 1096, 40, 207, 1150, 942, 1847, 516, 1564, 1558, 911, 309, 824, 974, 1896, 717, 334, 1674, 1509, 743, 126, 1335, 590, 386, 1969, 800, 1683, 670, 1414, 1804, 1123, 124, 1428, 1195, 286, 1809, 1005, 406, 797, 1904, 295, 944, 1128, 493, 1727, 803, 90, 312, 142, 1106, 485, 709, 504, 1212, 1237, 1881, 761, 863, 654, 473, 37, 84, 417, 1207, 1421, 1270, 589, 1729, 1419, 134, 215, 449, 1986, 1779, 1763, 213, 757, 1619, 1544, 1317, 1323, 278, 1331, 201, 17, 1939, 457, 1868, 980, 1567, 884, 420, 771, 1596, 1659, 450, 1945, 1345, 874, 1378, 153, 653, 953, 856, 454, 1152, 53, 1624, 1475, 347, 1791, 981, 1858, 805, 1138, 194, 1080, 1339, 1548, 537, 93, 1288, 307, 151, 379, 821, 1010, 1963, 1236, 508, 979, 1256, 1980, 921, 316, 755, 211, 988, 511, 608, 1474, 913, 1952, 1911, 164, 794, 1621, 1425, 651, 1688, 1907, 1774, 1458, 1404, 948, 214, 920, 1229, 1781, 1666, 422, 1009, 968, 684};
	// int const_array[] = {1240, 1270, 428, 528, 1635, 1374, 1353, 883, 467, 444, 967, 1683, 1803, 501, 102, 299, 26, 1772, 862, 124, 966, 1773, 1251, 1493, 23, 1473, 276, 62, 395, 670, 1076, 1367, 1718, 291, 194, 409, 1757, 237, 1305, 956, 1110, 1078, 296, 411, 272, 1134, 1756, 198, 696, 1499, 1289, 977, 955, 1763, 484, 20, 1731, 223, 1729, 525, 868, 1588, 1228, 455, 1494, 40, 1376, 438, 213, 1006, 1299, 1717, 32, 1073, 14, 982, 612, 783, 840, 831, 722, 1407, 1447, 1908, 354, 1143, 307, 1013, 876, 171, 799, 498, 445, 366, 94, 78, 83, 1876, 1307, 195};
	// int const_array[] = {0, 10, 15, 11, 5, 2, 6, 7, 3, 1, 9, 26};

	int *array_of_indexes = ft_calloc(1, sizeof(const_array));
	int *array_of_numbers = ft_calloc(1, sizeof(const_array));
	int len = (int)(sizeof(const_array) / sizeof(int));

	// copy const_array to the heap in array_of_numbers
	ft_memcpy(array_of_numbers, const_array, sizeof(const_array));
	i = 0;
	while (i < len)
	{
		array_of_indexes[i] = i;
		i++;
	}

	// setup stack A and B
	stack *A = ft_calloc(1, sizeof(stack));
	stack *B = ft_calloc(1, sizeof(stack));

	A->array_of_nums = ft_calloc(len, sizeof(num));
	A->lenght = len;

	B->array_of_nums = ft_calloc(len, sizeof(num));
	B->lenght = 0;

	// feed numbers
	i = 0;
	while (i < len)
	{
		A->array_of_nums[i].value = array_of_numbers[i];
		i++;
	}

	printf("\n=========== MAIN ===========\n");
	// printf("\nnumbers before sorting:\n");
	// i = 0;
	// while (i < len)
	// 	printf("%4d ", array_of_numbers[i++]);
	// printf("\n");
	sort_array(array_of_numbers, array_of_indexes, len);
	// printf("\n");

	// feed indexes
	i = 0;
	while (i < len)
	{
		A->array_of_nums[array_of_indexes[i]].index = i;
		i++;
	}
	// printf("\n\nnumbers after sorting:\n");
	// i = 0;
	// while (i < len)
	// 	printf("%4d ", array_of_numbers[i++]);
	// printf("\n\nindexes after sorting:\n");
	// i = 0;
	// while (i < len)
	// 	printf("%4d ", array_of_indexes[i++]);
	// printf("\n\nstack A:\n");
	// i = 0;
	// while (i < A->lenght)
	// 	printf("%4d ", A->array_of_nums[i++].value);
	// printf("\n");
	// i = 0;
	// while (i < A->lenght)
	// 	printf("%4d ", A->array_of_nums[i++].index);
	// printf("\n\nstack B:\n");
	// i = 0;
	// while (i < B->lenght)
	// 	printf("%4d ", B->array_of_nums[i++].value);

	// test rotate, reverse rotate and push
	// if (len % 2 == 0)
	// 	cut_from_stack(A, B, len / 2);
	// else
	cut_from_stack(A, B, len / 2);
	printf("\n\nA: ");
	i = 0;
	while (i < A->lenght)
		printf("%4d ", A->array_of_nums[i++].value);
	printf("\n\nB: ");
	i = 0;
	while (i < B->lenght)
		printf("%4d ", B->array_of_nums[i++].value);
	printf("\n\nnumber of moves %d\n", moves);
	/////////////////////////////////////////////////////

	printf("\n\n");
}