books = [0,0,0,0,0]
original_total_books = 0
rates = [1,0.95,0.90,0.80,0.75]
price_per_book = 800

# discount/books ratio
# offer_choices = [0/1,5/2,10/3,20/4,25/5]
offer_choices = [0,2,3,5,5]

def total(basket):
    costs = []
    top_offer = max(offer_choices)
    # this is literaly brute force: computing based on all 
    # best offers. They can be multiple with similar value per item
    # Not the best algorithm. I better algorithm is needed
    for index,offer in enumerate(offer_choices):
        if offer == top_offer:
            prep_books(basket)
            val = compute(index)
            costs.append(val)
    return min(costs)

def compute(max_group_size):
    global books, price_per_book, original_total_books
    cost = 0
    books_count = 0
    while(original_total_books > 0):
        books_count = 0
        for index,val in enumerate(books[:max_group_size+1]):
            if(val>0):
                books[index] -= 1
                books_count += 1

        cost += books_count*(price_per_book*rates[books_count-1])
        books.sort(reverse = True)
        original_total_books -= books_count
    return cost

def prep_books(basket):
    global books, original_total_books
    for entry in basket:
        books[entry-1] += 1
    original_total_books = len(basket)
    books.sort(reverse = True)
