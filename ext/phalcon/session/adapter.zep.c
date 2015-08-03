
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/string.h"


/**
 * Phalcon\Session\Adapter
 *
 * Base class for Phalcon\Session adapters
 */
ZEPHIR_INIT_CLASS(Phalcon_Session_Adapter) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Session, Adapter, phalcon, session_adapter, phalcon_session_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_session_adapter_ce, SL("_uniqueId"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalcon_session_adapter_ce, SL("_started"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_session_adapter_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_session_adapter_ce, SL("SESSION_ACTIVE"), 2 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_session_adapter_ce, SL("SESSION_NONE"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_session_adapter_ce, SL("SESSION_DISABLED"), 0 TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Session\Adapter constructor
 *
 * @param array options
 */
PHP_METHOD(Phalcon_Session_Adapter, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *options = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &options);

	if (!options) {
		options = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(options) == IS_ARRAY) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setoptions", NULL, 0, options);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Starts the session (if headers are already sent the session will not be started)
 */
PHP_METHOD(Phalcon_Session_Adapter, start) {

	zend_bool _2;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1, *_3 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&_0, "headers_sent", NULL, 54);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		_1 = zephir_fetch_nproperty_this(this_ptr, SL("_started"), PH_NOISY_CC);
		_2 = !zephir_is_true(_1);
		if (_2) {
			ZEPHIR_CALL_METHOD(&_3, this_ptr, "status", NULL, 0);
			zephir_check_call_status();
			_2 = !ZEPHIR_IS_LONG_IDENTICAL(_3, 2);
		}
		if (_2) {
			ZEPHIR_CALL_FUNCTION(NULL, "session_start", NULL, 55);
			zephir_check_call_status();
			zephir_update_property_this(this_ptr, SL("_started"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			RETURN_MM_BOOL(1);
		}
	}
	RETURN_MM_BOOL(0);

}

/**
 * Sets session's options
 *
 *<code>
 *	$session->setOptions(array(
 *		'uniqueId' => 'my-private-app'
 *	));
 *</code>
 */
PHP_METHOD(Phalcon_Session_Adapter, setOptions) {

	zval *options_param = NULL, *uniqueId;
	zval *options = NULL;

	zephir_fetch_params(0, 1, 0, &options_param);

	options = options_param;



	if (zephir_array_isset_string_fetch(&uniqueId, options, SS("uniqueId"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_uniqueId"), uniqueId TSRMLS_CC);
	}
	zephir_update_property_this(this_ptr, SL("_options"), options TSRMLS_CC);

}

/**
 * Get internal options
 */
PHP_METHOD(Phalcon_Session_Adapter, getOptions) {


	RETURN_MEMBER(this_ptr, "_options");

}

/**
 * Set session name
 */
PHP_METHOD(Phalcon_Session_Adapter, setName) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

	zephir_get_strval(name, name_param);


	ZEPHIR_CALL_FUNCTION(NULL, "session_name", NULL, 56, name);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Get session name
 */
PHP_METHOD(Phalcon_Session_Adapter, getName) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("session_name", NULL, 56);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * {@inheritdoc}
 */
PHP_METHOD(Phalcon_Session_Adapter, regenerateId) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *deleteOldSession_param = NULL;
	zend_bool deleteOldSession;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &deleteOldSession_param);

	if (!deleteOldSession_param) {
		deleteOldSession = 1;
	} else {
		deleteOldSession = zephir_get_boolval(deleteOldSession_param);
	}


	ZEPHIR_CALL_FUNCTION(NULL, "session_regenerate_id", NULL, 57, (deleteOldSession ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false)));
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Gets a session variable from an application context
 *
 *<code>
 *	$session->get('auth', 'yes');
 *</code>
 */
PHP_METHOD(Phalcon_Session_Adapter, get) {

	zend_bool remove;
	zval *index_param = NULL, *defaultValue = NULL, *remove_param = NULL, *value, *key = NULL, *uniqueId, *_SESSION;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	zephir_fetch_params(1, 1, 2, &index_param, &defaultValue, &remove_param);

	zephir_get_strval(index, index_param);
	if (!defaultValue) {
		defaultValue = ZEPHIR_GLOBAL(global_null);
	}
	if (!remove_param) {
		remove = 0;
	} else {
		remove = zephir_get_boolval(remove_param);
	}


	uniqueId = zephir_fetch_nproperty_this(this_ptr, SL("_uniqueId"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(uniqueId))) {
		ZEPHIR_INIT_VAR(key);
		ZEPHIR_CONCAT_VSV(key, uniqueId, "#", index);
	} else {
		ZEPHIR_CPY_WRT(key, index);
	}
	ZEPHIR_OBS_VAR(value);
	if (zephir_array_isset_fetch(&value, _SESSION, key, 0 TSRMLS_CC)) {
		if (remove) {
			zephir_array_unset(&_SESSION, key, PH_SEPARATE);
		}
		RETURN_CCTOR(value);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	RETURN_MM();

}

/**
 * Sets a session variable in an application context
 *
 *<code>
 *	$session->set('auth', 'yes');
 *</code>
 */
PHP_METHOD(Phalcon_Session_Adapter, set) {

	int _2;
	zval *index_param = NULL, *value, *uniqueId, *_SESSION, *_0, *_1 = NULL;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	zephir_fetch_params(1, 2, 0, &index_param, &value);

	zephir_get_strval(index, index_param);


	uniqueId = zephir_fetch_nproperty_this(this_ptr, SL("_uniqueId"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(uniqueId))) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_uniqueId"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VSV(_1, _0, "#", index);
		_2 = zephir_maybe_separate_zval(&_SESSION);
		zephir_array_update_zval(&_SESSION, _1, &value, PH_COPY | PH_SEPARATE);
		if (_2) {
			ZEND_SET_SYMBOL(&EG(symbol_table), "_SESSION", _SESSION);
		}
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_uniqueId"), PH_NOISY_CC);
	ZEPHIR_INIT_LNVAR(_1);
	ZEPHIR_CONCAT_VSV(_1, _0, "#", index);
	_2 = zephir_maybe_separate_zval(&_SESSION);
	zephir_array_update_zval(&_SESSION, _1, &value, PH_COPY | PH_SEPARATE);
	if (_2) {
		ZEND_SET_SYMBOL(&EG(symbol_table), "_SESSION", _SESSION);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether a session variable is set in an application context
 *
 *<code>
 *	var_dump($session->has('auth'));
 *</code>
 */
PHP_METHOD(Phalcon_Session_Adapter, has) {

	zval *index_param = NULL, *uniqueId, *_SESSION, *_0, *_1;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(index, index_param);


	uniqueId = zephir_fetch_nproperty_this(this_ptr, SL("_uniqueId"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(uniqueId))) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_uniqueId"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VSV(_1, _0, "#", index);
		RETURN_MM_BOOL(zephir_array_isset(_SESSION, _1));
	}
	RETURN_MM_BOOL(zephir_array_isset(_SESSION, index));

}

/**
 * Removes a session variable from an application context
 *
 *<code>
 *	$session->remove('auth');
 *</code>
 */
PHP_METHOD(Phalcon_Session_Adapter, remove) {

	zval *index_param = NULL, *uniqueId, *_0, *_1, *_SESSION;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(index, index_param);


	uniqueId = zephir_fetch_nproperty_this(this_ptr, SL("_uniqueId"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(uniqueId))) {
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("_uniqueId"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_VSV(_1, _0, "#", index);
		zephir_array_unset(&_SESSION, _1, PH_SEPARATE);
	}
	zephir_array_unset(&_SESSION, index, PH_SEPARATE);
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns active session id
 *
 *<code>
 *	echo $session->getId();
 *</code>
 */
PHP_METHOD(Phalcon_Session_Adapter, getId) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_FUNCTION("session_id", NULL, 58);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Set the current session id
 *
 *<code>
 *	$session->setId($id);
 *</code>
 */
PHP_METHOD(Phalcon_Session_Adapter, setId) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *id_param = NULL;
	zval *id = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	zephir_get_strval(id, id_param);


	ZEPHIR_CALL_FUNCTION(NULL, "session_id", NULL, 58, id);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Check whether the session has been started
 *
 *<code>
 *	var_dump($session->isStarted());
 *</code>
 */
PHP_METHOD(Phalcon_Session_Adapter, isStarted) {


	RETURN_MEMBER(this_ptr, "_started");

}

/**
 * Destroys the active session
 *
 *<code>
 *	var_dump($session->destroy());
 *	var_dump($session->destroy(true));
 *</code>
 */
PHP_METHOD(Phalcon_Session_Adapter, destroy) {

	int ZEPHIR_LAST_CALL_STATUS;
	HashTable *_2;
	HashPosition _1;
	zval *removeData = NULL, *prefix, *key = NULL, *_SESSION = NULL, *_0 = NULL, **_3, *_4 = NULL, *_5 = NULL;

	ZEPHIR_MM_GROW();
	zephir_get_global(&_SESSION, SS("_SESSION") TSRMLS_CC);
	zephir_fetch_params(1, 0, 1, &removeData);

	if (!removeData) {
		removeData = ZEPHIR_GLOBAL(global_false);
	}


	if (zephir_is_true(removeData)) {
		ZEPHIR_OBS_VAR(prefix);
		zephir_read_property_this(&prefix, this_ptr, SL("_uniqueId"), PH_NOISY_CC);
		if (!(ZEPHIR_IS_EMPTY(prefix))) {
			ZEPHIR_INIT_VAR(_0);
			zephir_is_iterable(_SESSION, &_2, &_1, 1, 0, "phalcon/session/adapter.zep", 263);
			for (
			  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
			  ; zephir_hash_move_forward_ex(_2, &_1)
			) {
				ZEPHIR_GET_HMKEY(key, _2, _1);
				ZEPHIR_GET_HVALUE(_0, _3);
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_VS(_4, prefix, "#");
				if (zephir_start_with(key, _4, NULL)) {
					ZEPHIR_INIT_LNVAR(_5);
					ZEPHIR_CONCAT_VSV(_5, prefix, "#", key);
					zephir_array_unset(&_SESSION, _5, PH_SEPARATE);
				}
			}
		} else {
			ZEPHIR_INIT_NVAR(_SESSION);
			array_init(_SESSION);
		}
	}
	zephir_update_property_this(this_ptr, SL("_started"), (0) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	ZEPHIR_RETURN_CALL_FUNCTION("session_destroy", NULL, 59);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Returns the status of the current session. For PHP 5.3 this function will always return SESSION_NONE
 *
 *<code>
 *	var_dump($session->status());
 *
 *  // PHP 5.4 and above will give meaningful messages, 5.3 gets SESSION_NONE always
 *  if ($session->status() !== $session::SESSION_ACTIVE) {
 *      $session->start();
 *  }
 *</code>
 */
PHP_METHOD(Phalcon_Session_Adapter, status) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *status = NULL;

	ZEPHIR_MM_GROW();

	if (!(zephir_is_php_version(50300))) {
		ZEPHIR_CALL_FUNCTION(&status, "session_status", NULL, 60);
		zephir_check_call_status();
		do {
			if (ZEPHIR_IS_LONG(status, 0)) {
				RETURN_MM_LONG(0);
			}
			if (ZEPHIR_IS_LONG(status, 2)) {
				RETURN_MM_LONG(2);
			}
		} while(0);

	}
	RETURN_MM_LONG(1);

}

/**
 * Alias: Gets a session variable from an application context
 */
PHP_METHOD(Phalcon_Session_Adapter, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(index, index_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "get", NULL, 0, index);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias: Sets a session variable in an application context
 */
PHP_METHOD(Phalcon_Session_Adapter, __set) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL, *value;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &index_param, &value);

	zephir_get_strval(index, index_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "set", NULL, 0, index, value);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias: Check whether a session variable is set in an application context
 */
PHP_METHOD(Phalcon_Session_Adapter, __isset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(index, index_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "has", NULL, 0, index);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Alias: Removes a session variable from an application context
 */
PHP_METHOD(Phalcon_Session_Adapter, __unset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *index_param = NULL;
	zval *index = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &index_param);

	zephir_get_strval(index, index_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "remove", NULL, 0, index);
	zephir_check_call_status();
	RETURN_MM();

}

