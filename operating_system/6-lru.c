#include <stdio.h>
int main()
{
    int pages[50], frames[10], n_pages, n_frames;
    int i, j, k, hit = 0, isHit;
    int counter = 0, time[10], flag, lru_index;
    float hit_ratio, miss_ratio;
    printf("=== LRU Page Replacement Algorithm ===\n");
    printf("Enter the number of pages: ");
    scanf("%d", &n_pages);
    printf("Enter the page reference string:\n");
    for (i = 0; i < n_pages; i++)
    {
        scanf("%d", &pages[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d", &n_frames);
    for (i = 0; i < n_frames; i++)
    {
        frames[i] = -1;
        time[i] = 0;
    }
    printf("\nPage Replacement Process:\n");
    for (i = 0; i < n_pages; i++)
    {
        isHit = 0;
        counter++;
        for (j = 0; j < n_frames; j++)
        {
            if (frames[j] == pages[i])
            {
                hit++;
                isHit = 1;
                time[j] = counter; // Update last used time
                break;
            }
        }
        if (!isHit)
        {
            int min_time = time[0];
            lru_index = 0;
            for (j = 1; j < n_frames; j++)
            {
                if (time[j] < min_time)
                {
                    min_time = time[j];
                    lru_index = j;
                }
            }
            frames[lru_index] = pages[i];
            time[lru_index] = counter;
            printf("Page %d: MISS\t\t", pages[i]);
        }
        else
        {
            printf("Page %d: HIT\t\t", pages[i]);
        }
        for (j = 0; j < n_frames; j++)
        {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }
    hit_ratio = (float)hit / n_pages;
    miss_ratio = 1 - hit_ratio;
    printf("\nTotal Page Hits  = %d", hit);
    printf("\nTotal Page Misses = %d", n_pages - hit);
    printf("\nHit Ratio = %.2f", hit_ratio);
    printf("\nMiss Ratio = %.2f\n", miss_ratio);
    return 0;
}
