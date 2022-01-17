# 1

**With a linear page table, you need a single register to locate the page table, assuming that hardware does the lookup upon a TLB miss. How many registers do you need to locate a two-level page table? A three-level table?**

I believe two-level page tables require 2 registers which store the first-directory and second-file register. Similarly, three-level tables require 3 registers.

# 2

**Use the simulator to perform translations given random seeds 0, 1, and 2, and check your answers using the -c flag. How many memory references are needed to perform each lookup?**

```
python paging-multilevel-translate.py -s 0 -c
```

```
Virtual Address 611c:
  --> pde index:0x18 [decimal 24] pde contents:0xa1 (valid 1, pfn 0x21 [decimal 33])
    --> pte index:0x8 [decimal 8] pte contents:0xb5 (valid 1, pfn 0x35 [decimal 53])
      --> Translates to Physical Address 0x6bc --> Value: 08
```

It stayed the same for seed 1, 2. We need to refer 6 memory references which are virtual address, pds index, pde contents, pte index, pte contents, physical address.

# 3

**Given your understanding of how cache memory works, how do you think memory references to the page table will behave in the cache? Will they lead to lots of cache hits (and thus fast accesses?) Or lots of misses (and thus slow accesses)?**

It will lead to lots of cache hits due to the time and spacial locality technique.
