# Report of CS4293 Assignment 1

[TOC]

## Secret-Key Encryption

### Task 1:  Frequency Analysis Against Monoalphabetic Substitution Cipher

* Answer: The key of encryption is `vgapnbrtmosicuxejhqyzflkdw` corresponds to `abcdefghijklmnopqrstuvwxyz`

* Explanation: I used the [online decrypting resource](<http://www.richkni.co.uk/php/crypta/freq.php>) to analyze the character frequency and compared it with the frequency [bigram](<https://en.wikipedia.org/wiki/Bigram>) and [trigram](<https://en.wikipedia.org/wiki/Trigram>). I also used the [word finder](<https://word.tips/>). By **selecting all the words with length two and three** and comparing the result, we can find that the most possible mapping is (`plain<=> cypher`): 

* Code (Select words with specific length): 

  ```python
  import operator
  with open('ciphertext.txt', 'r') as file:
  	words = file.read().split()
      dic = {}
      for word in words:
          if len(word) == 3:
              if not word in dic :
                  dic[word] = 1
              else:
                  dic[word] += 1
       sorted_dic = sorted(dic.items(), key=lambda kv:kv[1])
       print(sorted_dic)
  ```

* Observation:

  * Steps to find the key

  ```
  (1) the <=> ytn: 
  {e <=> n, h <=> t, t <=> y}
  (2) three <=> ythnn (guess): 
  {e <=> n, h <=> t, r <=> h, t <=> y}
  (3) that <=> ytvy :  
  {a <=> v, e <=> n, h <=> t, r <=> h, t <=> y}
  (4) to <=> yx :
  {a <=> v, e <=> n, h <=> t, o <=> x, r <=> h, t <=> y}
  (5) of <=> xb :
  {a <=> v, e <=> n, f <=> b, h <=> t, o <=> x, r <=> h, t <=> y}
  (6) it <=> my
  {a <=> v, e <=> n, f <=> b, h <=> t, i <=> m, o <=> x, r <=> h, t <=> y}
  (7) in <=> mu, on <=> xu, no <=> ux
  {a <=> v, e <=> n, f <=> b, h <=> t, i <=> m, n <=> u, o <=> x, r <=> h, t <=> y}
  (8) all <=> vii, which <=> ltmat, until a winner <=> zuymi v lmuunh
  {a <=> v, c <=> a, e <=> n, f <=> b, h <=> t, i <=> m, l <=> i, n <=> u, o <=> x, r <=> h, t <=> y, u <=> z, w <=> l}
  (9) is <=> mq
  {a <=> v, c <=> a, e <=> n, f <=> b, h <=> t, i <=> m, l <=> i, n <=> u, o <=> x, r <=> h, s <=> q, t <=> y, u <=> z, w <=> l}
  (10) about <=> vgxzy, seems <=> qnncq, right <=> hmrty
  {abcefghilmnorstuw <=> vganbrtmicuxhqyzl}
  (11) awards <=> vlvhpq, just <=> ozqy, like <=> imsn, trip <=> yhme, quit <=> jzmy, harvey <=> tvhfnd, extra <=> nkyhv, they <=> ytnd
  {abcdefghijklmnopqrstuvwxyz <=> vgapnbrtmosicuxejhqyzflkdw}
  ```

  * Words with length 2 and 3

  ![1579335280495](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579335280495.png)

  ![1579338582398](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579338582398.png)

  * Frequency

    * one character

      ![1579329814006](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579329814006.png)

    * two character

      ![1579329506891](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579329506891.png)

    * three character

      ![1579328805721](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579328805721.png)

-----------------------------

### Task 2: Encryption using Different Ciphers and Modes

* Observation

  * Use `s -aes-128-cbc`

    * command

    ![1579342171019](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342171019.png)

    * encrypted binary file

    ![1579342102099](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342102099.png)

    * decrypted file

    ![1579342144057](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342144057.png)

  * Use `-bf-cbc`

    * command line

    ![1579342370293](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342370293.png)

    * encrypted binary file

    ![1579342277795](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342277795.png)

    * decrypted file

    ![1579342326581](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342326581.png)

  * Use `-aes-128-cfb`

    * command

    ![1579342541148](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342541148.png)

    * encrypted binary file

    ![1579342518751](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342518751.png)

    * decrypted file

    ![1579342495551](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342495551.png)

  * Use different algorithms to encode and decode

    * command line

    ![1579342655197](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342655197.png)

    * decrypted file by using different algorithm => does not work (use wrong key to decrypt also doesn’t work)

    ![1579342634791](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579342634791.png)

--------------------------------

### Task 3: Encryption Mode - ECB vs. CBC

* Observation

  * Command line

    ![1579410582687](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579410582687.png)

  * Comparison between three pictures

    ![1579410767273](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579410767273.png)

* Explanation: ECB is basically raw cipher (i.e. same input and key will result into same cipher text) , while CBC is step-by-step cipher which takes the output of the previous cipher and performs XOR with a block of plaintext. The first output is produced by first plaintext block and initialization vector. Therefore, ECB will preserve some features of the original image, while CBC will not. 

------------------------------------

### Task 4: Padding

* Observation

  * ECB: Has padding

    ![1579412656739](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579412656739.png)

  * CBC: Has padding

    ![1579412044015](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579412044015.png)

  * CFB: No padding

    ![1579412947219](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579412947219.png)

  * OFB: No padding

    ![1579413112390](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1579413112390.png)

* Explanation: 

  * The block ciphers require specific block size. 

  * Once the plaintext is not dividable to equal-sized blocks, there will be exactly one smaller block, which will be the last block in the encryption pipeline. 

  * For modes CFB and OFB, the last block of plaintext will not be used by the block cipher (as shown below).

    ![Screen Shot 2020-01-19 at 3.47.57 PM](Deheng_Zhang-55199998-CS4293-Assignment1.assets/Screen Shot 2020-01-19 at 3.47.57 PM.png)

    ![Screen Shot 2020-01-19 at 3.48.03 PM](Deheng_Zhang-55199998-CS4293-Assignment1.assets/Screen Shot 2020-01-19 at 3.48.03 PM.png)

------------------

### Task 5: Error Propagation – Corrupted Cipher Text

* Answer: The number of blocks corrupted in ECB, CBC, CFB, OFB are 1 block, 2 blocks, 2 blocks, and 1 block respectively. 

* Observation

  * Create: Use `generator.py`: 

    ```python
    with open("1000bytes.txt", "w") as file:
        for i in range(0, 1000):
            file.write(str(i%10))
    ```

    ![Screen Shot 2020-01-20 at 9.38.37 PM](Deheng_Zhang-55199998-CS4293-Assignment1.assets/Screen Shot 2020-01-20 at 9.38.37 PM.png)

  * Encrypt (Use ECB as an example)

    ![Screen Shot 2020-01-20 at 9.43.01 PM](Deheng_Zhang-55199998-CS4293-Assignment1.assets/Screen Shot 2020-01-20 at 9.43.01 PM.png)

  * Edit: I use [online bless](<https://hexed.it/?hl=en>) to simulate the data corruption: 

    ![Screen Shot 2020-01-20 at 10.05.04 PM](Deheng_Zhang-55199998-CS4293-Assignment1.assets/Screen Shot 2020-01-20 at 10.05.04 PM.png)

  * Decryption: Decryption:  

    * ECB: The result is the same as I expected, only one block is corrupted. Besides, all bytes in the corrupted block is corrupted. 

      ![Screen Shot 2020-02-22 at 5.15.16 PM](Deheng_Zhang-55199998-CS4293-Assignment1.assets/Screen Shot 2020-02-22 at 5.15.16 PM-2362934.png)

    * CBC: The result is the same as I expected, only two blocks are corrupted. Besides, all bytes in the corrupted block is corrupted while only one byte in the next block is corrupted

      ![Screen Shot 2020-02-22 at 5.11.05 PM](Deheng_Zhang-55199998-CS4293-Assignment1.assets/Screen Shot 2020-02-22 at 5.11.05 PM-2362685.png)

    * CFB: The result is the same as I expected, only two blocks are corrupted. Besides, **only one byte in the corrupted block is corrupted while all bytes in the next block is corrupted**

      ![Screen Shot 2020-02-22 at 5.19.47 PM](Deheng_Zhang-55199998-CS4293-Assignment1.assets/Screen Shot 2020-02-22 at 5.19.47 PM.png)

    * OFB: The result is the same as I expected, only one block is corrupted. Besides, only one byte (the 55th) is corrupted

      ![Screen Shot 2020-02-22 at 5.21.33 PM](Deheng_Zhang-55199998-CS4293-Assignment1.assets/Screen Shot 2020-02-22 at 5.21.33 PM.png)

* Explanation (red color represents bit error):

  * Notice that encryption function $E​$ and decryption function $D​$ makes sure **each bits of output are dependent to each bits of input**, while each bits of output of XOR is only dependent on two bits of two inputs. 

  * ECB: Because only $\color{red}{P_i} = D_k(\color{red}{C_i})​$ depends on the error block. 

  * CBC: Because for CBC decryption
    $$
    \color{red}{P_i }= D_k(\color{red}{C_i})\oplus C_{i-1}, \color{red}{P_{i+1}} = D_k(C_{i+1})\oplus\color{red}{ C_{i}}
    $$

  * CFB: Because for CFB decryption
    $$
    \color{red}{P_i}= E_k({C_{i-1}})\oplus \color{red}{C_{i}}, \color{red}{P_{i+1}} = E_k(\color{red}{C_{i}})\oplus {C_{i+1}}
    $$

  * OFB: Because for CFB decruption
    $$
    \color{red}{P_i} = \color{red}{C_i} \oplus E_k^{(i+1)}(IV) \\
    E^{(i+1)}_k\ represents\ apply\ encryption\ for\ i+1\ times
    $$


-----------------------

### Task 6: Initial Vector (IV)

#### Task 6.1

* Observation: The same plaintext with same key and same IV results in same cipher text, while different IV results in different cipher text

  ![Screen Shot 2020-02-22 at 6.10.43 PM](Deheng_Zhang-55199998-CS4293-Assignment1.assets/Screen Shot 2020-02-22 at 6.10.43 PM.png)

* Explanation: IV should be unique to make sure the cipher text is different for two encryption with same plain text and key to avoid attacking. 

#### Task 6.2

* Answer: P2 can be decrypted because:
  $$
  {C1} = {P1_0} \oplus E^{(0+1)}(key,IV)||{P1_1} \oplus E^{(1+1)}(key,IV)||...||{P1_n} \oplus E_k^{(n+1)}(IV) \\
  {C2} = {P2_0} \oplus E^{(0+1)}(key,IV)||{P2_1} \oplus E^{(1+1)}(key,IV)||...||{P2_n} \oplus E_k^{(n+1)}(IV) \\
  P1 \oplus C1 \oplus C2 = P2_0 || P2_1 || ... || P2_n = P2
  $$

* Code: 

  ![Screen Shot 2020-02-22 at 6.45.55 PM](Deheng_Zhang-55199998-CS4293-Assignment1.assets/Screen Shot 2020-02-22 at 6.45.55 PM.png)

* If we replace OFB with CFB: 
  $$
  C1 = E(key, IV) \oplus P1_0 || E(key, C1_0) \oplus P1_1 || ... || E(key, C1_{n-1}) \oplus P1_n \\
  C2 = E(key, IV) \oplus P2_0 || E(key, C2_0) \oplus P2_1 || ... || E(key, C1_{n-1}) \oplus P2_n \\
  P1_0\oplus C1_0 \oplus C2_0 \\
   = P1_0 \oplus E(key, IV) \oplus P1_0 \oplus E(key, IV) \oplus P2_0 = P2_0 \\
  $$

* Answer: $E(key, C1_0)$ and $E(key, C2_0)$ cannot be cancelled, therefore **only the first block can be revealed** 

#### Task 6.3

* In this case, the message only contains one block: 
  $$
  C1 = E(key, P1 \oplus IV1) \\
  C2 = E(key, P2 \oplus IV2) \\
  $$

* To construct a message, we set:
  $$
  P1^\prime = "Yes" \\
  
  P2 = P1^\prime \oplus IV1 \oplus IV2 \\
  
  C2 = E(key, (P1^\prime \oplus IV1 \oplus IV2)\oplus IV2 ) \\
   = E(key, P1^\prime \oplus IV1)
  $$

* We know that for 1-block aes, the outputs of same inputs are the same, therefore we check $C2 \oplus C1$, if the result is $0$, $P1$ is $Yes$, otherwise $P1$ is $No$ 

--------------------

### Task 7: Programming using the Crypto Library

* Code: `myenv.cpp`

  ```cpp
  #include <openssl/evp.h>
  #include <string.h>
  #include <stdio.h>
  #define ENCRYPT 1
  #define DECRYPT 0
  
  unsigned char* do_crypt( unsigned char* intext, unsigned char* key, 
                           unsigned char* iv, int do_encrypt
  ){
     unsigned char* ans = (unsigned char*) malloc(1024) ;
     memset(ans, 0, 1024);
     unsigned char outbuf[1024];
     int outlen, tmplen;
  
     EVP_CIPHER_CTX ctx;
     /* Don't set key or IV right away; we want to check lengths */
     EVP_CIPHER_CTX_init(&ctx);
     EVP_CipherInit_ex(&ctx, EVP_aes_128_cbc(), NULL, NULL, NULL,
             do_encrypt);
     OPENSSL_assert(EVP_CIPHER_CTX_key_length(&ctx) == 16);
     OPENSSL_assert(EVP_CIPHER_CTX_iv_length(&ctx) == 16);
     /* Now we can set key and IV */
     EVP_CipherInit_ex(&ctx, NULL, NULL, key, iv, do_encrypt);
  
    if(!EVP_EncryptUpdate(&ctx, outbuf, &outlen, intext, 32)){
      /* Error */
      return 0;
    }
    if(!EVP_EncryptFinal_ex(&ctx, outbuf + outlen, &tmplen)){
      /* Error */
      return 0;
    }
    outlen += tmplen;
    EVP_CIPHER_CTX_cleanup(&ctx);
    memcpy(ans, outbuf, outlen);
    return ans;
  }
  
  int hex_to_int(char c){
    if(c<='9'&&c>='0'){
      return c-'0' + 0;
    } else {
      return c-'a' + 10;
    }
  }
  
  int hex_to_ascii(char c, char d){
    int high = hex_to_int(c) * 16;
    int low = hex_to_int(d);
    return high+low;
  }
  
  int main(){
    FILE* word_list = fopen("./assignment1-words.txt", "rb");
  
    // Convert hex cipher text into string
    unsigned char ciphertext[32];
    const char* tmp 
    = "764aa26b55a4da654df6b19e4bce00f4ed05e09346fb0e762583cb7da2ac93a2";
    int length = strlen(tmp);
    char buf = 0;
    for(int i = 0; i < length; i++){
      if(i % 2 != 0){
        ciphertext[i/2] = hex_to_ascii(buf, tmp[i]);
      }else{
        buf = tmp[i];
      }
    }
  
    unsigned char iv[16];
    const char* tmp2 = "aabbccddeeff00998877665544332211";
    length = strlen(tmp2);
    buf = 0;
    for(int i = 0; i < length; i++){ 
      if(i % 2 != 0){
        iv[i/2] = hex_to_ascii(buf, tmp2[i]);
      }else{
        buf = tmp2[i];
      }
    }
  
    size_t len = 0;
    char* line = (char*)malloc(1024);
    ssize_t read;
    int word_i = 0;
    while ((read = getline(&line, &len, word_list)) != -1) {
        unsigned char key[17];
        char key2[17];
        for(int i=0;i<16;i++){
          if(i<(int)(read)-1){
            key2[i] = key[i] = line[i];
          } else {
            key2[i] = key[i] = '#';
          }
        }
        key2[16] = key[16] = 0;       
        unsigned char* ans = do_crypt(ciphertext, key, iv, DECRYPT);
        if(ans){
          char check_ans[22];
          for(int i=0; i< 21;i++){
            check_ans[i] = ans[i];
          }      
          check_ans[21] = 0;
          if(strcmp(check_ans, "This is a top secret.") == 0){
            printf("%s\n", key2);
          }
        } 
    }
    return 0;
  }
  
  ```

* Answer: key: `Syracuse########` 

  ![1582527929671](Deheng_Zhang-55199998-CS4293-Assignment1.assets/1582527929671.png)

---------------------------------

## MD5 Collision Attack

### Task 8: Generating Two Different Files with the Same MD5 Hash



-----------------

### Task 9: Understanding MD5’s Property



-----------------

### Task 10: Generating Two Executable Files with the Same MD5 Hash 



-------------------

### Task 11: Making the Two Programs Behave Differently



-----------------

## RSA Public-Key Encryption and Signature

### Task 12: Deriving the Private Key



----------------

### Task 13: Encrypting a Message



------------------

### Task 14: Decrypting a Message



---------------

### Task 15: Signing a Message



------------------

### Task 16: Verifying a Message



-------------------

### Task 17: Manually Verifying an X.509 Certificate





## Pseudo Random Number Generation

### Task 18: Generate Encryption Key in a Wrong Way

* Observation

  * With `srand`: Seems right.

    ![Screen Shot 2020-01-19 at 4.01.19 PM](Deheng_Zhang-55199998-CS4293-Assignment1.assets/Screen Shot 2020-01-19 at 4.01.19 PM.png)

  * Without `srand`: All the “random” numbers are the same.

    ![Screen Shot 2020-01-19 at 4.03.03 PM](Deheng_Zhang-55199998-CS4293-Assignment1.assets/Screen Shot 2020-01-19 at 4.03.03 PM.png)

* Explanation: 

  * `srand` will pass a seed to the `c++` random number generator. And the `rand` function will generate a pseudo random number based on the given seed. 
  * `time` function is used to use the current time as the seed, since the number genrating function is highly non-linear, the result will be partialy “random”. 

---------

### Task 19: Guessing the Key

* Command line: 

  ![Screen Shot 2020-01-19 at 6.20.14 PM](Deheng_Zhang-55199998-CS4293-Assignment1.assets/Screen Shot 2020-01-19 at 6.20.14 PM.png)

* 

---------

### Task 20: Measure the Entropy of Kernel



--------------------

### Task 21: Get Pseudo Random Numbers from `/dev/random`



--------------------

### Task 22: Get Random Numbers from `/dev/urandom `



-------------------

