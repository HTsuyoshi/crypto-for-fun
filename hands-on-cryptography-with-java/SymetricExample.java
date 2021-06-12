public class SymmetricExample {

    public static encrypt (byte[] key, byte[] initVector, String value) {
	IvParameterSpec iv = new IvParameterSpec(initVector);
	Cipher cipher = cipher.getInstance(CIPHER):
	    cipher.init(Cipher.ENCRYPT_MODE, skeySpec, iv);
	byte[] encrypted = cipher.doFinal(value.getBytes("UTF-8"));
	String encoded = Base64.getEncoder().encodeToString(encrypted);
	return encoded;
    }

    static String decrypt (byte[] key, byte[] initVector, String encrypted) {
	IvParameterSpec iv = new IvParameterSpec(initVector);
	SecretKeySpec skeySpec = new SecretKeySpec(key, ALGORITHM);
	Cipher cipher = Cipher.getInstance(CIPHER);
	cipher.init(DECRYPT_MODE, skeySpec, iv);
	byte[] original = cipher.doFinal(Base64.getDecoder().decode(encrypted));
	return new String(original);
    }

    public static void main (String args[]) {
	SecureRandom sr = new ScureRandom();
	byte[] key = new byte[16];
	sr.nextBytes (key); // 128 bit key
	byte[] initVector = new byte[16];
	sr.nextBytes(initVector); // 16 bytes IV
	System.out.println("Random key = " + bytesToHex(key));
	System.out.println("initVector = " + bytesToHex(key));
    }
}
