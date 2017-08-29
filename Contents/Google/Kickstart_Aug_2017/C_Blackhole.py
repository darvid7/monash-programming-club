T = int(input())

for t in range(T):
    blackhole_1 = [int(x) for x in input().split()]
    blackhole_2 = [int(x) for x in input().split()]
    blackhole_3 = [int(x) for x in input().split()]

    # For small data set, only x value will change.
    min_max = (
        min(
            blackhole_1[0],
            blackhole_2[0],
            blackhole_3[0]
        ),
        max(
            blackhole_1[0],
            blackhole_2[0],
            blackhole_3[0]
        )
    )
    range_to_cover = abs(min_max[0] - min_max[1])
    print("Case #{0}: {1:.10f}".format(t + 1, (range_to_cover/3)/2))
