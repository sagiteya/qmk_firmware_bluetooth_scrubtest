LEADER_EXTERNS();

void matrix_scan_user(void) {
 LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_P) {
      // Anything you can do in a macro.
      register_code(KC_LCTL);
      register_code(KC_PRINT_SCREEN);
      unregister_code(KC_PRINT_SCREEN);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(SG_SCLN) {
      // Anything you can do in a macro.
     register_code(KC_LALT);
      register_code(KC_PRINT_SCREEN);
      unregister_code(KC_PRINT_SCREEN);
      unregister_code(KC_LALT);
    }
    SEQ_TWO_KEYS(SG_B, Q_A) {
      register_code16(BM_BAHA);
      unregister_code16(BM_BAHA);
    }
    SEQ_THREE_KEYS(Q_A, KC_R, SG_D) {
      register_code16(BM_PROHARD);
      unregister_code16(BM_PROHARD);
      
    //  SEND_STRING("https://start.duckduckgo.com\n");
    }
    SEQ_TWO_KEYS(KC_R, KC_O) {
      register_code16(BM_BROD);
      unregister_code16(BM_BROD);
  
    }
    SEQ_ONE_KEY(Q_A) {
      // Anything you can do in a macro.
      register_code(KC_LCTL);
      register_code(KC_A);
      unregister_code(KC_A);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(SG_B) {
      // Anything you can do in a macro.
      register_code(KC_LCTL);
      register_code(KC_B);
      unregister_code(KC_B);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(Q_Z) {
      // Anything you can do in a macro.
      register_code(KC_LCTL);
      register_code(KC_Z);
      unregister_code(KC_Z);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(SG_X) {
      // Anything you can do in a macro.
      register_code(KC_LCTL);
      register_code(KC_X);
      unregister_code(KC_X);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(SG_C) {
      // Anything you can do in a macro.
      register_code(KC_LCTL);
      register_code(KC_C);
      unregister_code(KC_C);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(SG_V) {
      // Anything you can do in a macro.
      register_code(KC_LCTL);
      register_code(KC_V);
      unregister_code(KC_V);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(SG_B) {
      // Anything you can do in a macro.
      register_code(KC_LCTL);
      register_code(KC_B);
      unregister_code(KC_B);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(SG_S) {
      // Anything you can do in a macro.
      register_code(KC_LCTL);
      register_code(KC_LSFT);
      register_code(KC_S);
      unregister_code(KC_S);
      unregister_code(KC_LSFT);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(SG_Q) {
      // Anything you can do in a macro.
      register_code(KC_LCTL);
      register_code(KC_HOME);
      unregister_code(KC_HOME);
      unregister_code(KC_LCTL);
    }
    SEQ_ONE_KEY(SG_W) {
      // Anything you can do in a macro.
      register_code(KC_LCTL);
      register_code(KC_END);
      unregister_code(KC_END);
      unregister_code(KC_LCTL);
    }

    SEQ_ONE_KEY(SG_F) {
      // Anything you can do in a macro.
      register_code(KC_LCTL);
      register_code(KC_F);
      unregister_code(KC_F);
      unregister_code(KC_LCTL);
  }

}
}