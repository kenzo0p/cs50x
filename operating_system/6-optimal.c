#include <stdio.h>

int findOptimal(int frames[], int n_frames, int pages[], int n_pages, int current_index)
{
    int i, j;
    int farthest = current_index;
    int res = -1;

    for (i = 0; i < n_frames; i++)
    {
        int j;
        for (j = current_index; j < n_pages; j++)
        {
            if (frames[i] == pages[j])
            {
                if (j > farthest)
                {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        // If page not found in future, replace this immediately
        if (j == n_pages)
        {
            return i;
        }
    }
    // If all pages are found in future, replace the one with farthest use
    if (res == -1)
        return 0;
    else
        return res;
}

int main()
{
    int pages[50], frames[10], n_pages, n_frames;
    int i, j, k, hit = 0, isHit;
    float hit_ratio, miss_ratio;

    printf("=== Optimal Page Replacement Algorithm ===\n");

    printf("Enter the number of pages: ");
    scanf("%d", &n_pages);

    printf("Enter the page reference string:\n");
    for (i = 0; i < n_pages; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &n_frames);

    // Initialize frames
    for (i = 0; i < n_frames; i++)
    {
        frames[i] = -1;
    }

    printf("\nPage Replacement Process:\n");

    for (i = 0; i < n_pages; i++)
    {
        isHit = 0;

        // Check if page is already in frame (Hit)
        for (j = 0; j < n_frames; j++)
        {
            if (frames[j] == pages[i])
            {
                hit++;
                isHit = 1;
                break;
            }
        }

        if (!isHit)
        {
            // Find empty frame or replace using optimal logic
            int replaced = 0;
            for (j = 0; j < n_frames; j++)
            {
                if (frames[j] == -1)
                {
                    frames[j] = pages[i];
                    replaced = 1;
                    break;
                }
            }
            if (!replaced)
            {
                int opt_index = findOptimal(frames, n_frames, pages, n_pages, i + 1);
                frames[opt_index] = pages[i];
            }
            printf("Page %d: MISS\t\t", pages[i]);
        }
        else
        {
            printf("Page %d: HIT\t\t", pages[i]);
        }

        // Print frames
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
