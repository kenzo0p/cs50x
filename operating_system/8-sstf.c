#include <stdio.h>
#include <stdlib.h>
int main()
{
    int RQ[100], i, n, TotalHeadMoment = 0, initial, count = 0;
    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests sequence\n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d", &initial);
    // logic for sstf disk scheduling
    /* loop will execute until all process is completed*/
    while (count != n)
    {
        int min = 1000, d, index;
        for (i = 0; i < n; i++)
        {
            d = abs(RQ[i] - initial);
            if (min > d)
            {
                min = d;
                index = i;
            }
        }
        TotalHeadMoment = TotalHeadMoment + min;

        initial = RQ[index];
        // 1000 is for max
        // you can use any number
        //marking 1000 so it will never get choosen again
        RQ[index] = 1000;
        count++;
    }
    printf("Total head movement is %d\n", TotalHeadMoment);
    return 0;
}


/*
Ok these notes will be short… EXACT exam practical revision style… **based on the codes we used**
So when you look 5 mins before external — this is enough to recall.

---

# Disk Scheduling Short Notes (Based on our Codes)

### Why Disk Scheduling?

Used to decide the optimal order of servicing disk I/O requests so that **total head movement is minimum**. Head movement = seek time.

---

## FCFS

* serve requests in order given
* simple, fair
* large total movement possible
  (no priority / no optimization)

---

## SSTF (Shortest Seek Time First)

* at every step choose the request **closest** to current head
* reduces seek time effectively
* can cause starvation (far requests may wait forever)
* Code logic: find minimum `abs(RQ[i] - head)` each iteration

---

## SCAN (Elevator)

* head moves in one direction till **boundary** (0 or last track)
* then reverses direction
* good average performance
* *must touch boundary* even if no request there
  → this is why extra movement `head → size-1` or `head → 0` is added.

---

## CSCAN (Circular SCAN)  (just concept because code same pattern like SCAN)

* moves only in one direction
* after reaching boundary → jumps directly to opposite boundary
  (not reverse scanning)
* uniform waiting time

---

## LOOK

* same like SCAN but **does not** go till boundary
* stops at last actual request

---

## CLOOK

* same like CSCAN but **does not** go till boundary
* circular jump to smallest request directly

---

### Sorting Importance

All LOOK / SCAN / CLOOK family first **sort** requests so direction-based traversal is possible.

---

### viva one-liner define Disk Scheduling

Disk scheduling algorithms minimize total head movement by deciding a good order to serve disk I/O requests.

---

# Final Hint to Remember Differences

| Algo  | Goes to boundary? | Circular? |
| ----- | ----------------- | --------- |
| SCAN  | Yes               | No        |
| CSCAN | Yes               | Yes       |
| LOOK  | No                | No        |
| CLOOK | No                | Yes       |

---

If you revise this exact page before exam — you are fully safe for disk scheduling viva.

---

Next OS topic after this?
**Mutual Exclusion / Semaphores practical codes** or **Deadlocks**?


*/