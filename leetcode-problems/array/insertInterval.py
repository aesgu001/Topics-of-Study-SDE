# 57. Insert Interval
# https://leetcode.com/problems/insert-interval/

###################################################################################################
#
#   def insertInterval(intervals, newInterval):
#   1.  Initalize start and end indices to 0
#   2.  For each interval in intervals:
#   3.      If newInterval.start <= interval.start or newInterval.start <= interval.end:
#   4.          break
#   5.      Else:
#   6.          ++start, ++end
#   7.  For each interval in intervals[start:]:
#   8.      If newInterval.end <= interval.end:
#   9.          break
#   10.     Else:
#   11.         ++end
#   12. If start == intervals.length:
#   13.     intervals.append(newInterval)
#   14. Else if newInterval.start < newInteral.end < intervals[start].start:
#   15.     insert newInterval at intervals[start]
#   16. Else if newInterval.start < intervals[start].start <= intervals[start].end
#           < newInterval.end:
#   17.     intervals[start].start = newInterval.start
#   18.     intervals[start].end = max(newInterval.end, intervals[end].end)
#   19.     Remove intervals[start + 1 : end]
#   20. Else if intervals[start].start <= newInterval.start <= intervals[start].end
#           < newInterval.end:
#   21.     Repeat steps 18 - 19
#   22. Return intervals
#
#   Time complexity:    O(N) to search for start and end points from each interval
#                       O(N) to remove overlapped intervals as a result of new interval
#                       O(N) + O(N) = O(N)
#   Space complexity:   O(1) no extra space needed to update intervals
#
###################################################################################################
def insertInterval(intervals, newInterval):
    start = 0
    end = 0

    # Find starting index for new interval
    for i in range(0, len(intervals)):
        if newInterval[0] <= intervals[i][0] or newInterval[0] <= intervals[i][1]:
            break
        else:
            start += 1
            end += 1
    
    # Continue and find ending index
    for i in range(start, len(intervals)):
        if newInterval[1] <= intervals[i][1]:
            break
        else:
            end += 1

    # Add new interval at end
    if start == len(intervals):
        intervals.append(newInterval)

    elif intervals[start][0] > newInterval[0]:
        if intervals[start][0] > newInterval[1]:
            # start_n - end_n - start_i - ...
            intervals.insert(start, newInterval)
        else:
            intervals[start][0] = newInterval[0]
            if intervals[start][1] < newInterval[1]:
                # start_n - start_i - end_i - ... - end_n
                # Update end interval to max(newInterval.end, intervals[end].end)
                if end == len(intervals) or newInterval[1] < intervals[end][0]:
                    intervals[start][1] = newInterval[1]
                else:
                    intervals[start][1] = intervals[end][1]
                    end += 1
                # Pop intervals within its range
                for _ in range(start + 1, end):
                    intervals.pop(start + 1)

    # intervals[start][0] <= newInterval[0]
    else:
        if intervals[start][1] < newInterval[1]:
            # start_i - start_n - end_i - ... - end_n
            if end == len(intervals) or newInterval[1] < intervals[end][0]:
                intervals[start][1] = newInterval[1]
            else:
                intervals[start][1] = intervals[end][1]
                end += 1
            for _ in range(start + 1, end):
                intervals.pop(start + 1)

    return intervals

# Test cases
interval1 = [[1, 3], [6, 9]]
newInterval1 = [2, 5]
print(insertInterval(interval1, newInterval1))

interval2 = [[1, 2], [3, 5], [6, 7], [8, 10], [12, 16]]
newInterval2 = [4, 8]
print(insertInterval(interval2, newInterval2))

interval3 = [[1, 5]]
newInterval3 = [0, 6]
print(insertInterval(interval3, newInterval3))
