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
    SEQ_ONE_KEY(KC_SEMICOLON) {
      // Anything you can do in a macro.
     register_code(KC_LALT);
      register_code(KC_PRINT_SCREEN);
      unregister_code(KC_PRINT_SCREEN);
      unregister_code(KC_LALT);
    }
    SEQ_TWO_KEYS(KC_B, Q_A) {
      register_code16(BM_BAHA);
      unregister_code16(BM_BAHA);
    }
    SEQ_THREE_KEYS(KC_A, KC_R, KC_D) {
      register_code16(BM_PROHARD);
      unregister_code16(BM_PROHARD);
      
    //  SEND_STRING("https://start.duckduckgo.com\n");
    }
    SEQ_TWO_KEYS(KC_R, KC_O) {
      register_code16(BM_BROD);
      unregister_code16(BM_BROD);
      
      
    }
  }

}
