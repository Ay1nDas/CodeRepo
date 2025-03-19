// export let cart = [
//   {
//     productID: 'e43638ce-6aa0-4b85-b27f-e1d07eb678c6',
//     quantity: 2,
//   },
//   {
//     productID: '15b6fc6f-327a-4ec4-896f-486349e85a3d',
//     quantity: 1,
//   },
//   {
//     productID: '83d4ca15-0f35-48f5-b7a3-1ea210004f2e',
//     quantity: 3,
//   },
//   {
//     productID: '54e0eccd-8f36-462b-b68a-8182611d9add',
//     quantity: 6,
//   },
// ];

export let cart = JSON.parse(localStorage.getItem('cart')) || [];

export let totalCartItem =
  JSON.parse(localStorage.getItem('totalCartItem')) || 0;

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
      deliveryId: '1',
    });

    totalCartItem += 1;
  }

  saveCartToLocal();
}

export function deleteItem(index) {
  const removeId = cart[index].productID;
  totalCartItem -= cart[index].quantity;
  cart.splice(index, 1);

  saveCartToLocal();
  return removeId;
}

export function saveCartToLocal() {
  localStorage.setItem('cart', JSON.stringify(cart));
  localStorage.setItem('totalCartItem', JSON.stringify(totalCartItem));
}

export function changeDelivery(productId, delOptId) {
  cart.forEach((cartItem) => {
    if (cartItem.productID === productId) {
      cartItem.deliveryId = delOptId;
      localStorage.setItem('cart', JSON.stringify(cart));
    }
  });
}
