export let cart = [];
export let totalCartItem = 0;

export function addToCart(productID) {
  let isPush = true;

  cart.forEach((cartItem) => {
    if (cartItem.productID === productID) {
      isPush = false;
      cartItem.quantity += 1;
      totalCartItem += 1;
    }
  });

  if (isPush) {
    cart.push({
      productID: productID,
      quantity: 1,
    });

    totalCartItem += 1;
  }
}
