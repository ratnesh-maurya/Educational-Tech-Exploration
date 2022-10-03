def merge(intervals: List[List[int]]) -> List[List[int]]:
    intervals.sort()
    out = [intervals[0]]
    for i in intervals:
        if i[0] <= out[-1][1]:
            out[-1][1] = max(i[1], out[-1][1])
        else:
            out.append(i)
    return out

# intervals = [[1,3],[2,6],[8,10],[15,18]]
# Output: [[1,6],[8,10],[15,18]]
intervals = [[1,3],[2,6],[8,10],[15,18]]
print(merge(intervals))